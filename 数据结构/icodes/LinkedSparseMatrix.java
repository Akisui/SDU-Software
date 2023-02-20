
/** linked representation of a sparse matrix */

package dataStructures;

import java.util.*;
import java.lang.reflect.*;
import utilities.*;
import wrappers.*;

public class LinkedSparseMatrix
{
   // nested top-level classes
   static class RowElement
   {
      // data members
      int col;       // column index of the term
      Object value;  // term value
   
      // constructors
      RowElement(int theColumn, Object theValue)
      {
         col = theColumn;
         value = theValue;
      }

      RowElement() {}
   
      /** convert the term into a string so it can be output */
      public String toString()
         {return new String("column = " + col + " value = " + value);}
   }

   static class HeaderElement
   {
      // data members
      int row;                 // row index of chain
      ExtendedChain rowChain;  // chain of nonzero terms for this row
   
      // constructors
      HeaderElement(int theRow, ExtendedChain theChain)
      {
         row = theRow;
         rowChain = theChain;
      }

      HeaderElement(int theRow)
         {this(theRow, new ExtendedChain());}

      HeaderElement() {}
   
      /** convert the row value into a string so it can be output */
      public String toString()
         {return new String("row = " + row);}
   }


   // data members
   int rows;                    // number of rows in matrix
   int cols;                    // number of columns in matrix
   Object zero;                 // zero element
   ExtendedChain headerChain;   // header node chain

   // constructors
   // parameter estimatedMaxSize provided for compatibility
   // with SparseMatrixAsExtendedArrayList
   public LinkedSparseMatrix(int theRows, int theColumns,
                             int estimatedMaxSize, Object theZero)
   {
      // validate theRows and theColumns
      if (theRows < 0 || theColumns < 0)
         throw new IllegalArgumentException
               ("number of rows and columns must be >= 0");
      if ((theRows == 0 && theColumns != 0) ||
          (theRows != 0 && theColumns == 0))
         throw new IllegalArgumentException
               ("both the number of rows and columns must equal " +
                "zero or both must be > 0");
   
      // create the matrix
      rows = theRows;
      cols = theColumns;
      zero = theZero;
      headerChain = new ExtendedChain();
   }
   
   /** use a default estimated maximum size of 1 */
   public LinkedSparseMatrix(int theRows, int theColumns, Object theZero)
      {this(theRows, theColumns, 1, theZero);}
   
   /** defaults are rows = cols = estimatedMaxSize = 1 */
   public LinkedSparseMatrix(Object theZero)
      {this(1, 1, 1, theZero);}
   
   // methods
   /** convert the matrix into a string so it can be output */
   public String toString()
   {
      StringBuffer s = new StringBuffer(); 

      // put matrix characteristics into s
      s.append("rows = " + rows + "  columns = " + cols + "\n");
   
      if (headerChain.isEmpty())  // matrix is empty
         s.append("No nonzero terms \n");
      else
      {// at least one nonzero term
         // access rows using an iterator for headerChain
         Iterator ih = headerChain.iterator();
         while (ih.hasNext())
         {
            HeaderElement hElement = (HeaderElement) ih.next(); 
            // put the row number into the string
            s.append(hElement.toString() + "\n");

            // put the row chain elements into the string
            // indent each element
            Iterator ir = hElement.rowChain.iterator();
            while (ir.hasNext())
               s.append("   " + ir.next() + "\n");
         }
      }
   
      // create equivalent String
      return new String(s);
   }
   
   /** input a sparse matrix into this from the given input stream */
   public static LinkedSparseMatrix input(Object theZero,
                                          MyInputStream stream)
   {
      Method inputMethod;
      Object [] inputMethodArgs = {stream};
      Class [] parameterTypes = {MyInputStream.class};
      try
      {
         // get the proper method to be used to read in the values
         inputMethod = theZero.getClass().
                          getMethod("input", parameterTypes);

         // create a default matrix for input
         LinkedSparseMatrix x = new LinkedSparseMatrix(theZero);
   
         // input matrix characteristics
         System.out.println("Enter number of rows, columns, " +
                            "and nonzero terms");
         x.rows = stream.readInteger();
         x.cols = stream.readInteger();
         int size = stream.readInteger();
         x.headerChain = new ExtendedChain();
      
         // should validate input values here, left as an exercise
   
         // create fictional row zero
         HeaderElement rowHeader = new HeaderElement(0);
                                       // current row's header node
      
         // input the nonzero terms
         for (int i = 0; i < size; i++)
         {  
             System.out.println("Enter row and column of term " + (i+1));
             RowElement newTerm = new RowElement();
             int newRow = stream.readInteger();
             newTerm.col = stream.readInteger();
             newTerm.value = inputMethod.invoke(null, inputMethodArgs);
             // should validate input, left as an exercise
 
             // check if new term is part of current row
             if (newRow > rowHeader.row)
             {// start a new row
                // add header node rowHeader of current row to header
                // node chain x.headerChain only if row is not zero
                if (rowHeader.row > 0) x.headerChain.add(rowHeader);
       
                // prepare rowHeader for new row
                rowHeader = new HeaderElement(newRow);
             }
       
             // add new term to row chain
             rowHeader.rowChain.add(newTerm);
         }   
   
         // take care of last row of matrix
         if (rowHeader.row > 0) x.headerChain.add(rowHeader);
   
         return x;
      }
      catch (Exception e)
      {
         System.out.println(e);
         throw new IllegalArgumentException
            ("bad input");
      }
   }

   /** @return the transpose of this
     * matrix values are not cloned */
   public LinkedSparseMatrix transpose()
   {
      // create result matrix
      LinkedSparseMatrix t = new LinkedSparseMatrix(cols, rows, zero);
   
      // create bins to collect rows of t
      ExtendedChain [] bin = new ExtendedChain [cols + 1];
      for (int i = 1; i <= cols; i++)
          bin[i] = new ExtendedChain();
       
      // create row i of t in bin[i], 1 <= i <= cols
      // iterator for header node chain
      Iterator ih = headerChain.iterator();
      while (ih.hasNext())
      {// copy all terms in a row chain
          HeaderElement header = (HeaderElement) ih.next();  
          // iterator for the row chain
          Iterator ir = header.rowChain.iterator();
          while (ir.hasNext())
          {// copy a term from the row chain into a bin
              RowElement y = (RowElement) ir.next();

              // create term for a bin
              RowElement z = new RowElement(header.row, y.value);
              // z will eventually be in row y.col of t
              bin[y.col].add(z);
          }
      }

      // assemble header node chain of t
      for (int i = 1; i <= cols; i++)
         if (!bin[i].isEmpty())
         // row i of t is nonempty
            t.headerChain.add(new HeaderElement(i, bin[i]));

      return t;
   }


   /** test program */
   public static void main(String [] args)
   {
      MyInteger myZero = new MyInteger(0);
      LinkedSparseMatrix a, b;

      // define a MyInputStream object to input from System.in
      MyInputStream keyboard = new MyInputStream();

      // test input and output
      a = LinkedSparseMatrix.input(myZero, keyboard);
      System.out.println("The matrix a is");
      System.out.println(a);
      System.out.println();
      b = LinkedSparseMatrix.input(myZero, keyboard);
      System.out.println("The matrix b is");
      System.out.println(b);
      System.out.println();

      // test transpose
      System.out.println("The transpose of a is");
      System.out.println(a.transpose());
      System.out.println();
   }
}

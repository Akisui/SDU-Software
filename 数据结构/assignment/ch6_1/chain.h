#include <bits/stdc++.h>
#include "linearList.h"
#include "chainNode.h"
#include "myExceptions.h"

using namespace std;

template<class T>
class chain : public linearList<T>
{
    public:
        // constructor, copy constructor and destructor
        chain(int initialCapacity = 10);
        chain(const chain<T>&);
        ~chain();

        // ADT methods
        bool empty() const {return listSize == 0;}
        int size() const {return listSize;}
        T& get(int theIndex) const;
        int indexOf(const T& theElement) const;
        void erase(int theIndex);
        void insert(int theIndex, const T& theElement);
        void output(ostream& out) const;
        void reverse(void);

    protected:
        // throw illegalIndex if theIndex invalid
        void checkIndex(int theIndex) const;
        chainNode<T>* firstNode;  // pointer to first node in chain
        int listSize;             // number of elements in list
};

template<class T>
chain<T>::chain(int initialCapacity)
{// Constructor.
    if (initialCapacity < 1)
    {
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << " Must be > 0";
        throw illegalParameterValue(s.str());
    }
    firstNode = NULL;
    listSize = 0;
}

template<class T>
// Copy constructor.
chain<T>::chain(const chain<T>& theList)
{
    
    listSize = theList.listSize;
    
    // theList is empty
    if (listSize == 0)
    {
        firstNode = NULL;
        return;
    }

    // non-empty list
    // node in theList to copy from
    chainNode<T>* sourceNode = theList.firstNode;
    // copy first element of theList
    firstNode = new chainNode<T>(sourceNode->element);
                
    sourceNode = sourceNode->next;
    // current last node in *this
    chainNode<T>* targetNode = firstNode;
       
    // copy remaining elements
    while (sourceNode != NULL)
    {
        
        targetNode->next = new chainNode<T>(sourceNode->element);
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }
    targetNode->next = NULL; // end the chain
}

template<class T>
// Chain destructor. Delete all nodes in chain.
chain<T>::~chain()
{
    // delete firstNode
    while (firstNode != NULL)
    {
        chainNode<T>* nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

template<class T>
// Verify that theIndex is between 0 and listSize - 1.
void chain<T>::checkIndex(int theIndex) const
{
    if (theIndex < 0 || theIndex >= listSize)
    {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }
}

template<class T>
// Return element whose index is theIndex.
T& chain<T>::get(int theIndex) const
{
    // Throw illegalIndex exception if no such element.
    checkIndex(theIndex);

    // move to desired node
    chainNode<T>* currentNode = firstNode;
    for (int i = 0; i < theIndex; i++)
       currentNode = currentNode->next;

    return currentNode->element;
}

template<class T>
// Return index of first occurrence of theElement.
// Return -1 if theElement not in list.
int chain<T>::indexOf(const T& theElement) const
{
    // search the chain for theElement
    chainNode<T>* currentNode = firstNode;
    int index = 0;  // index of currentNode
    while (currentNode != NULL &&
           currentNode->element != theElement)
    {
        // move to next node
        currentNode = currentNode->next;
        index++;
    }

   // make sure we found matching element
   if (currentNode == NULL)
      return -1;
   else
      return index;
}

template<class T>
// Delete the element whose index is theIndex.
void chain<T>::erase(int theIndex)
{
    // Throw illegalIndex exception if no such element.
    checkIndex(theIndex);

    // valid index, locate node with element to delete
    chainNode<T>* deleteNode;
    
    if (theIndex == 0)
    {
        // remove first node from chain
        deleteNode = firstNode;
        firstNode = firstNode->next;
    }
    else
    {
       // use p to get to predecessor of desired node
       chainNode<T>* p = firstNode;
       for (int i = 0; i < theIndex - 1; i++)
           p = p->next;
   
       deleteNode = p->next;
       p->next = p->next->next; // remove deleteNode from chain
    }
    listSize--;
    delete deleteNode;
}

template<class T>
// Insert theElement so that its index is theIndex.
void chain<T>::insert(int theIndex, const T& theElement)
{
    // invalid index
    if (theIndex < 0 || theIndex > listSize)
    {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }

    if (theIndex == 0)
        // insert at front
        firstNode = new chainNode<T>(theElement, firstNode);
    else
    {
        // find predecessor of new element
        chainNode<T>* p = firstNode;
        for (int i = 0; i < theIndex - 1; i++)
            p = p->next;
   
        // insert after p
        p->next = new chainNode<T>(theElement, p->next);
    }
    listSize++;
}

template<class T>
// Put the list into the stream out.
void chain<T>::output(ostream& out) const
{
    for (chainNode<T>* currentNode = firstNode;
         currentNode != NULL;
         currentNode = currentNode->next)
        out << currentNode->element << "  ";
}

// overload <<
template <class T>
ostream& operator<<(ostream& out, const chain<T>& x)
{
    x.output(out);
    return out;
}

// reverse the list
template <class T>
void chain<T>::reverse()
{
    // do nothing when only one element
    if(listSize < 2) return;
    
    // define current pointer
    chainNode<T>* currentNode = firstNode->next;
    firstNode->next = NULL;
    
    // iteration
    while(currentNode != NULL){
        // mark the next node
        chainNode<T>* nextNode = currentNode->next;
        
        // reverse the relation between currentNode and previousNode
        // ... which is firstNode in such condition
        currentNode->next = firstNode;
        
        // set currentNode as the firstNode
        firstNode = currentNode;
        
        // move the pointer
        currentNode = nextNode;
    }
}


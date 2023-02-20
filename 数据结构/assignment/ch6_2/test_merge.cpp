#include "extendedChain.h"
#include <iostream>
using namespace std;

// merge a and b to c
template <class T>
extendedChain<T> merge(extendedChain<T> a, extendedChain<T> b)
{
    extendedChain<T> c; // declare c
    while (a.size() && b.size()) // check if a or b is empty
    {
        // push the smaller element among a.front and b.front to c
        // which is the smallest element among all remained elements
        if (a.front() <= b.front()) // a.front is smaller
        {
            c.push_back(a.front());
            a.pop_front();
        }
        else // b.front is smaller
        {
            c.push_back(b.front());
            b.pop_front();
        }
    }
    // push remained elements in a or b
    while (a.size()) // if a is not empty
    {
        c.push_back(a.front());
        a.pop_front();
    }
    while (b.size()) // if b is not empty
    {
        c.push_back(b.front());
        b.pop_front();
    }
    return c;
}

int main(){
    extendedChain<int> a, b; // declare a, b
    for(int i = 1; i <= 20; i += 2) // set test elements
    {
        a.push_back(i); // a is an odd chain
        b.push_back(i + 1); // b is an even chain
    }
    extendedChain<int> c = merge(a, b); // merge a and b to c
    // print the process
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    return 0;
}

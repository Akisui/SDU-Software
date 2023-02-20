
#include <iostream>
#include "chain.h"

using namespace std;

int main()
{
    chain<int> testChain; // chain for test
    for (int i = 0; i < 15; ++i) // listSize = 15
        testChain.insert(i,i); // chain[i] = i
    cout << "testChain:\n\t" << testChain << endl;
    testChain.reverse(); // call reverse function
    cout << "testChain.reverse():\n\t" << testChain << endl;
    return 0;
}





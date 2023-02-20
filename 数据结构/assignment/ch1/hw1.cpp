#include <bits/stdc++.h>
using namespace std;

string sets[50]; // the set of elements
long long idx = 1; // initialization, which is described below
int n, maxn;

// print by condition(idx)
void print(long long idx) 
{
    cout << "{";
    bool flag = false; // determine whether it is the first output
    
    // traverse each element
    for (int i = 0; i < n; ++i) 
    {
        if (idx & 1) // "1" means "chosen"
        {
            // the first output needn't ","
            if (!flag) 
            {
                cout << sets[i]; // print the chosen element
                flag = true;
            }
            else cout << ", " << sets[i];
        }
        idx >>= 1; // check next bit
    }
    cout << "}" << endl;
}

// call print function and generate next idx
void subset(long long idx) 
{
    if (idx <= maxn)
    {
        print(idx); // print
        subset(idx + 1); // recursively generate
    }
    else return; // recursive boundary
}

void solve()
{  
    // enter the number of the elements.
    cin >> n; 

    // process the special case, which is empty set
    if (n == 0) 
    {
        cout << "{}" << endl;
        return; 
    }
    
    /* 
    for each elements, be chosen or not be chosen are denoted as 1 and 0, respectively
    idx : condition of elements presented by binary number, which converted to decimal number
    */

    // the largest idx
    maxn = (1 << n) - 1; 

    // enter the elements separated by space or newline
    for (int i = 0; i < n; ++i) cin >> sets[i]; 
    cout << "{}" << endl;
    
    // generate subset recursively and print
    subset(idx);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int maxn = 9;
int toeplitzMatrix[maxn] = {51, 41, 31, 21, 11, 12, 13, 14, 15};

int main()
{
    int n = 5;
    int i, j;
    cin >> i >> j;
    cout << toeplitzMatrix[n - 1 + j - i] << endl;
    return 0;
}

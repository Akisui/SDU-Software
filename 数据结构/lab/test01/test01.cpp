#include<iostream>
#include <algorithm>
using namespace std;

const int maxn = 25;
int a[maxn];
bool used[maxn];
int perm[maxn];

void permutation(int pos, int n)
{
    if (pos == n)
    {
        for (int i = 0; i < n; ++i)
        {
            if (i == 0) cout << a[perm[i]];
            else cout << "," << a[perm[i]];
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if (!used[i])
        {
            perm[pos] = i;
            used[i] = true;
            permutation(pos + 1, n);
            used[i] = false;
        }
    }
    return;
}

int main()
{
    int x;
    int cnt = 0;
    bool flag = true;
    cout << "Input" << endl;
    while (flag)
    {
        cin >> x;
        if (x == 0)
        {
            flag = false;
            break;
        }
        a[cnt++] = x;
    }
    cout << "Output" << endl;
    permutation(0, cnt);
    cout << "End0" << endl;
    return 0;
}

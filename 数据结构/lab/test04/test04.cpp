
#include <iostream>
using namespace std;

const int N = 10;
int p[N];
int ans[N][N];
int sizes[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cout << "Input" << endl;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) p[i] = i;
    int t;
    cin >> t;
    int a, b;
    char nano;
    while (t--)
    {
        cin >> nano >> a >> nano >> b >> nano;
        p[find(a)] = find(b);
    }
    int tmp;
    for (int i = 1; i <= n; ++i)
    {
        tmp = find(i);
        ans[tmp][sizes[tmp]++] = i;
    }
    cout << "Output" << endl;
    for (int i = 1; i <= n; ++i)
    {
        if (ans[i][0] == 0) continue;
        cout << "(";
        for (int j = 0; j <= n && ans[i][j] != 0; ++j)
        {
            if (j == 0)
            {
                cout << ans[i][j];
                continue;
            }
            cout << "," << ans[i][j];
        }
        cout << ")" << endl;
    }
    cout << "End0" << endl;
    return 0;
}

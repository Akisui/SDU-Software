
#include <iostream>
#include <vector>
using namespace std;

const int N = 100;
const int M = 200;

vector<int> ans;

int e[N], l[N], r[N], idx;
int e2[N], l2[N], r2[N], idx2;

void init(int e[], int l[], int r[])
{
    r[0] = 1, l[1] = 0;
    idx = 2;
}

int find(int x, int e[], int l[], int r[])
{
    for (int i = r[0]; i != 1; i = r[i])
        if (e[i] >= x) return i;
    return 1;
}

int find_2(int x, int e[], int l[], int r[])
{
    int cnt = 1;
    for (int i = r[0]; i != 1; i = r[i])
    {
        if (e[i] == x) return cnt;
        cnt++;
    }
    return 0;
}

void insert(int x, int e[], int l[], int r[])
{
    int next = find(x, e, l, r);
    e[idx] = x;
    r[idx] = next, l[idx] = l[next];
    r[l[next]] = idx, l[next] = idx++;
}

int x;
bool flag;
int main()
{
    init(e, l, r);
    cout << "Input1" << endl;

    flag = true;
    do
    {
        cin >> x;
        if (x == 0)
        {
            flag = false;

            continue;
        }
        insert(x, e, l, r);
    } while(flag);
    cout << "Output1" << endl;
    for (int i = r[0]; i != 1; i = r[i])
    {
        if (i == r[0])
        {
            cout << e[i];
            continue;
        }
        cout << "，" << e[i];
    }
    cout << endl;

    cout << "Input2" << endl;
    int t;
    cin >> t;
    insert(t, e, l, r);
    cout << "Output2" << endl;
    for (int i = r[0]; i != 1; i = r[i])
    {
        if (i == r[0])
        {
            cout << e[i];
            continue;
        }
        cout << "，" << e[i];
    }
    cout << endl;

    cout << "Input3" << endl;
    cin >> t;
    cout << "Output3" << endl;
    cout << find_2(t, e, l, r) << endl;

    cout << "Input4" << endl;
    cin >> t;
    cout << "Output4" << endl;
    cout << find_2(t, e, l, r) << endl;
    
    int tmp = idx;
    
    init(e2, l2, r2);
    idx = 2;
    cout << "Input5" << endl;
    flag = true;
    do
    {
        cin >> x;
        if (x == 0)
        {
            flag = false;
            continue;
        }
        insert(x, e2, l2, r2);
    } while(flag);
    cout << "Output5" << endl;
    for (int i = r2[0]; i != 1; i = r2[i])
    {
        if (i == r2[0])
        {
            cout << e2[i];
            continue;
        }
        cout << "，" << e2[i];
    }
    cout << endl;
    
    int i = r[0], j = r2[0];
    while (i != 1 && j != 1)
    {
        if (e[i] < e2[j])
        {
            ans.push_back(e[i]);
            i = r[i];
            
        }
        else
        {
            ans.push_back(e2[j]);
            j = r2[j];
            
        }
    }
    
    while (i != 1)
    {
        ans.push_back(e[i]);
        i = r[i];
    }
    while (j != 1)
    {
        ans.push_back(e2[j]);
        j = r2[j];
    }
    for (int i = 0; i < ans.size(); ++i)
    {
        if (i == 0)
        {
            cout << ans[i];
            continue;
        }
        cout << "，" << ans[i];
    }
    cout << endl;
    
    cout << "End0" << endl;
    return 0;
}

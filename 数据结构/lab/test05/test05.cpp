#include <bits/stdc++.h>
using namespace std;

stack<int> num;
stack<char> op;

unordered_map<char, int> h{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

void eval() // get the value
{
    // the second parameter
    int a = num.top();
    num.pop();
    // the first parameter
    int b = num.top();
    num.pop();
    // the operation on parameters above
    char p = op.top();
    op.pop();
    // result
    int r = 0;
    // calculus
    if (p == '+') r = b + a;
    if (p == '-') r = b - a;
    if (p == '*') r = b * a;
    if (p == '/') r = b / a;
    // return ans
    num.push(r);
}

void solve()
{
    cout << "Input" << endl;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i)
    {
        if (isdigit(s[i]))
        {
            int x = 0, j = i;
            while (j < s.size() && isdigit(s[j]))
            {
                x = x * 10 + s[j] - '0';
                ++j;
            }
            num.push(x);
            i = j - 1;
        }
        else if (s[i] == '(')
            op.push(s[i]);
        else if (s[i] == ')')
        {
            while (op.top() != '(') // calculus the ans in '()'
                eval();
            op.pop(); // remove '('
        }
        else
        {
            while (op.size() && h[op.top()] >= h[s[i]]) // top's op is greater
                eval();
            op.push(s[i]);
        }
    }
    while (op.size())
        eval();
    cout << "Output" << endl;
    cout << num.top() << endl;
    cout << "End0" << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <stdio.h>
using namespace std;

class adjacencyGraph
{
    public:
    
    adjacencyGraph(int n_input, int m_input)
    {
        n = n_input;
        m = m_input;
        for (int i = 0; i < 15; ++i)
            for (int j = 0; j < 15; ++j)
                graph[i][j] = 0x3f3f3f3f;
        dfs_flag = false;
        for (int i = 0; i < 15; ++i) dfs_reach[i] = false;
    }
    
    void insert(int a, int b, int cost)
    {
        graph[a][b] = (cost < graph[a][b] ? cost : graph[a][b]);
        graph[b][a] = graph[a][b];
    }
    
    int cost(int a, int b)
    {
        return graph[a][b];
    }
    
    void bfs(int root)
    {
        while (q.size() != 0) q.pop();
        bool reach[15];
        for (int i = 0; i < 15; ++i) reach[i] = false;

        q.push(root);
        reach[root] = true;

        bool flag = false;
        while (q.size() != 0)
        {
            int current = q.front();
            q.pop();
            if (!flag)
            {
                cout << current;
                flag = true;
            }         
            else cout << "," << current;
            for (int i = 1; i <= n; ++i)
            {
                if (i == current || graph[current][i] == 0x3f3f3f3f || reach[i]) continue;
                q.push(i);
                reach[i] = true;
            }
        }
        cout << endl;
        return;
    }

    void dfs(int current)
    {
        dfs_reach[current] = true;
        if (!dfs_flag)
        {
            cout << current;
            dfs_flag = true;
        }
        else cout << "," << current;

        for (int i = 1; i <= n; ++i)
        {
            if (graph[current][i] == 0x3f3f3f3f || dfs_reach[i]) continue;
            dfs(i);
        }
        return;
    }

    void dijkstra()
    {
        memset(dist, 0x3f, sizeof dist);
        for (int i = 0; i < 15; ++i) st[i] = false;
        dist[1] = 0;

        for (int i = 0; i < n - 1; i ++ )
        {
            int t = -1;
            for (int j = 1; j <= n; j ++ )
                if (!st[j] && (t == -1 || dist[t] > dist[j]))
                    t = j;

            for (int j = 1; j <= n; j ++ )
                dist[j] = min(dist[j], dist[t] + graph[t][j]);

            st[t] = true;
        }

        if (dist[n] == 0x3f3f3f3f) cout << 0 << endl;
        else cout << dist[n] << endl;
        return;
    }
   
    private:
    int graph[15][15]; 
    int n, m;
    bool dfs_flag;
    bool dfs_reach[15];
    bool st[15];
    int dist[15];
    queue<int> q;    
};

void solve()
{
    cout << "Input" << endl;
    int n, m;
    string input;
    cin >> input;
    sscanf(input.c_str(), "%d,%d", &n, &m);
    adjacencyGraph graph(n, m);
    int a_input, b_input, cost_input;
    while (m--)
    {
        cin >> input;
        sscanf(input.c_str(), "%d,%d,%d", &a_input, &b_input, &cost_input);
        graph.insert(a_input, b_input, cost_input);
    }
    cout << "Output" << endl;
    graph.bfs(1);
    graph.dfs(1);
    cout << endl;
    graph.dijkstra();
    cout << "End0" << endl;
    return;
}

int main()
{
    solve();
    return 0;
}
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream cin("bipartite.in");
ofstream cout("bipartite.out");

void dfs(int u, const vector<vector<int>> &g, vector<int> &color, int curColor = 1)
{
    color[u] = curColor;
    for (auto v : g[u])
        if (color[v] == 0)
        {
            dfs(v, g, color, -curColor);
        }
        else if (color[u] == color[v])
        {
            cout << "NO" << endl;
            exit(0);
        }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    vector<int> color(n);
    for (int i = 0; i < n; ++i)
        if (color[i] == 0)
            dfs(i, g, color);

    cout << "YES" << endl;

    return 0;
}
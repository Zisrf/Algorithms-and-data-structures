#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream cin("topsort.in");
ofstream cout("topsort.out");

void dfs(int u, const vector<vector<int>> &g, vector<int> &color, int parent = -1)
{
    color[u] = 1;
    for (auto v : g[u])
        if (color[v] == 1 && v != parent)
        {
            cout << -1 << endl;
            exit(0);
        }
        else if (color[v] == 0)
        {
            dfs(v, g, color, u);
        }
    color[u] = 2;
}

void topSort(int u, const vector<vector<int>> &g, vector<bool> &visited, vector<int> &ans)
{
    visited[u] = true;
    for (auto v : g[u])
        if (!visited[v])
            topSort(v, g, visited, ans);
    ans.push_back(u);
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
    }

    vector<int> color(n);
    for (int i = 0; i < n; ++i)
        if (color[i] == 0)
            dfs(i, g, color);

    vector<bool> visited(n, false);
    vector<int> ans;
    for (int i = 0; i < n; ++i)
        if (!visited[i])
            topSort(i, g, visited, ans);
    reverse(ans.begin(), ans.end());

    for (int i = 0; i < n; ++i)
        cout << ans[i] + 1 << ' ';
    cout << endl;

    return 0;
}
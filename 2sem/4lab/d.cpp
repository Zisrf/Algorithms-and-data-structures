#include <fstream>
#include <vector>
#include <cmath>
 
using namespace std;
 
const long long INF = 5e18;
 
void dfs(int u, const vector<vector<int>> &g, vector<bool> &onNegativeCycle)
{
    onNegativeCycle[u] = true;
    for (auto v : g[u])
        if (!onNegativeCycle[v])
            dfs(v, g, onNegativeCycle);
}
 
int main()
{
    ifstream cin("path.in");
    ofstream cout("path.out");
 
    int n, m, s;
    cin >> n >> m >> s;
    --s;
    vector<pair<pair<int, int>, long long>> R;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        --u;
        --v;
        R.push_back({{u, v}, w});
        g[u].push_back(v);
    }
 
    vector<long long> dist(n, INF);
    dist[s] = 0;
    for (int i = 0; i < n - 1; ++i)
        for (auto r : R)
        {
            int u = r.first.first;
            int v = r.first.second;
            long long w = r.second;
            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = max(dist[u] + w, -INF);
        }
 
    vector<bool> onNegativeCycle(n);
    for (int i = 0; i < n - 1; ++i)
        for (auto r : R)
        {
            int u = r.first.first;
            int v = r.first.second;
            long long w = r.second;
            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                if (!onNegativeCycle[u])
                    dfs(u, g, onNegativeCycle);
                dist[v] = dist[u] + w;
            }
        }
 
    for (int i = 0; i < n; ++i)
        if (onNegativeCycle[i])
            cout << '-' << endl;
        else if (dist[i] == INF)
            cout << '*' << endl;
        else
            cout << dist[i] << endl;
 
    return 0;
}
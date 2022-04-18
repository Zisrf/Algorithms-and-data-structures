#include <fstream>
#include <vector>
#include <set>
 
using namespace std;
 
const int INF = 2e9 + 11;
 
int main()
{
    ifstream fin("spantree3.in");
    ofstream fout("spantree3.out");
 
    int n, m;
    fin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        fin >> u >> v >> w;
        --u;
        --v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
 
    long long ans = 0;
    vector<int> d(n, INF);
    set<pair<int, int>> pq;
    vector<bool> used(n);
 
    d[0] = 0;
    pq.insert({d[0], 0});
    for (int i = 0; i < n; ++i)
    {
        int u = pq.begin()->second;
        pq.erase(pq.begin());
        ans += d[u];
        used[u] = true;
        for (auto [v, w] : g[u])
            if (!used[v] && w < d[v])
            {
                pq.erase({d[v], v});
                d[v] = w;
                pq.insert({d[v], v});
            }
    }
 
    fout << ans << endl;
 
    return 0;
}
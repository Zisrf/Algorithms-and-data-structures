#include <fstream>
#include <vector>
#include <set>
 
using namespace std;
 
const int INF = 2e9 + 11;
 
int main()
{
    ifstream fin("pathbgep.in");
    ofstream fout("pathbgep.out");
 
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
 
    vector<int> dist(n, INF);
    set<pair<int, int>> pq;
    dist[0] = 0;
    pq.insert({dist[0], 0});
 
    while (!pq.empty())
    {
        int u = pq.begin()->second;
        pq.erase(pq.begin());
 
        for (auto [v, w] : g[u])
            if (dist[u] + w < dist[v])
            {
                pq.erase({dist[v], v});
                dist[v] = dist[u] + w;
                pq.insert({dist[v], v});
            }
    }
 
    for (int i = 0; i < n; ++i)
        fout << dist[i] << ' ';
    fout << endl;
 
    return 0;
}
#include <fstream>
#include <vector>
#include <queue>
 
using namespace std;
 
const int INF = 2e9 + 11;
 
int main()
{
    ifstream cin("pathbge1.in");
    ofstream cout("pathbge1.out");
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    vector<int> dist(n, INF);
    queue<int> q;
    dist[0] = 0;
    q.push(0);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : g[u])
            if (dist[v] == INF)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
    }
 
    for (int i = 0; i < n; ++i)
        cout << dist[i] << ' ';
    cout << endl;
    
    return 0;
}
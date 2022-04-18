#include <fstream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
const int INF = 1e9;
 
int main()
{
    ifstream fin("negcycle.in");
    ofstream fout("negcycle.out");
 
    int n;
    fin >> n;
    vector<pair<pair<int, int>, int>> e;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            int w;
            fin >> w;
            if (w != INF)
                e.push_back({{i, j}, w});
        }
 
    vector<long long> dist(n, INF);
    vector<int> prev(n, -1);
    int x;
    dist[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        x = -1;
        for (auto r : e)
        {
            int u = r.first.first;
            int v = r.first.second;
            int w = r.second;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                prev[v] = u;
                x = v;
            }
        }
    }
 
    if (x == -1)
    {
        fout << "NO" << std::endl;
        return 0;
    }
 
    for (int i = 0; i < n; ++i)
            x = prev[x];
 
    vector<int> path;
    for (int cur = x;; cur = prev[cur])
    {
        path.push_back(cur);
        if (cur == x && path.size() > 1)
            break;
    }
    reverse(path.begin(), path.end());
 
    fout << "YES" << std::endl;
    fout << path.size() << std::endl;
    for (size_t i = 0; i < path.size(); ++i)
        fout << path[i] + 1 << ' ';
    fout << std::endl;
 
    return 0;
}
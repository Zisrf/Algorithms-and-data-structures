#include <fstream>
#include <vector>
 
using namespace std;
 
const int INF = 2e9 + 11;
 
int main()
{
    ifstream fin("pathsg.in");
    ofstream fout("pathsg.out");
 
    int n, m;
    fin >> n >> m;
    vector<vector<long long>> g(n, vector<long long>(n, INF));
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        fin >> u >> v >> w;
        --u;
        --v;
        g[u][v] = w;
    }
    for (int i = 0; i < n; ++i)
        g[i][i] = 0;
 
    for (int k = 0; k < n; ++k)
        for (int u = 0; u < n; ++u)
            for (int v = 0; v < n; ++v)
                if (g[u][k] + g[k][v] < g[u][v])
                    g[u][v] = g[u][k] + g[k][v];
 
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            fout << g[i][j] << ' ';
        fout << endl;
    }
 
    return 0;
}
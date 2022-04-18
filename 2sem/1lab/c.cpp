#include <fstream>
#include <vector>
 
using namespace std;
 
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
 
    int n, m;
    fin >> n >> m;
 
    vector<vector<bool>> g(n, vector<bool>(n));
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        fin >> u >> v;
        --u;
        --v;
        if (g[u][v])
        {
            fout << "YES" << endl;
            return 0;
        }
        else
        {
            g[u][v] = true;
            g[v][u] = true;
        }
    }
 
    fout << "NO" << endl;
    
    return 0;
}
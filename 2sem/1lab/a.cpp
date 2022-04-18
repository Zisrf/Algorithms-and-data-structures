#include <fstream>
#include <vector>
 
using namespace std;
 
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
 
    int n, m;
    fin >> n >> m;
 
    vector<vector<bool>> g(n, vector<bool>(n, false));
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        fin >> u >> v;
        g[u - 1][v - 1] = true;
    }
 
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n ; ++j)
            fout << g[i][j] << ' ';
        fout << endl;
    }
    
    return 0;
}
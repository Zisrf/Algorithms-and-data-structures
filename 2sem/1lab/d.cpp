#include <fstream>
#include <vector>
 
using namespace std;
 
void dfs(int u, vector<vector<int>> &g, vector<int> &color, int curColor)
{
    color[u] = curColor;
    for (auto v : g[u])
        if (color[v] == 0)
            dfs(v, g, color, curColor);
}
 
int main()
{
    ifstream fin("components.in");
    ofstream fout("components.out");
 
    int n, m;
    fin >> n >> m;
 
    vector<vector<int>> g(n);
    vector<int> color(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        fin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    int curColor = 1;
    for (int i = 0; i < n; ++i)
        if (color[i] == 0)
            dfs(i, g, color, curColor++);
 
    fout << curColor - 1 << endl;
    for (int i = 0; i < n; ++i)
        fout << color[i] << ' ';
    fout << endl;
    
    return 0;
}
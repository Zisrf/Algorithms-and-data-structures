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
    ifstream cin("components.in");
    ofstream cout("components.out");
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> g(n);
    vector<int> color(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    int curColor = 1;
    for (int i = 0; i < n; ++i)
        if (color[i] == 0)
            dfs(i, g, color, curColor++);
 
    cout << curColor - 1 << endl;
    for (int i = 0; i < n; ++i)
        cout << color[i] << ' ';
    cout << endl;
    
    return 0;
}
#include <fstream>
#include <vector>
 
using namespace std;
 
int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<bool>> g(n, vector<bool>(n));
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        if (g[u][v])
        {
            cout << "YES" << endl;
            return 0;
        }
        else
        {
            g[u][v] = true;
            g[v][u] = true;
        }
    }
 
    cout << "NO" << endl;
 
    cin.close();
    cout.close();
    return 0;
}
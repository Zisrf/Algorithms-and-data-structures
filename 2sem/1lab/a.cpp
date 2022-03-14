#include <fstream>
#include <vector>
 
using namespace std;
 
int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<bool>> g(n, vector<bool>(n, false));
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u - 1][v - 1] = true;
    }
 
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n ; ++j)
            cout << g[i][j] << ' ';
        cout << endl;
    }
 
    cin.close();
    cout.close();
    return 0;
}
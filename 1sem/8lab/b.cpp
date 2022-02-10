#include <fstream>
#include <vector>
 
using namespace std;
 
bool isDirected(int n, vector<vector<bool>> &g)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (g[i][i] || g[i][j] != g[j][i])
                return true;
    return false;
}
 
int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
 
    int n;
    cin >> n;
 
    vector<vector<bool>> g(n, vector<bool>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            bool buf;
            cin >> buf;
            g[i][j] = buf;
        }
 
    if (!isDirected(n, g))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
 
    cin.close();
    cout.close();
    return 0;
}
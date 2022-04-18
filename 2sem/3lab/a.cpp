#include <fstream>
#include <vector>
 
using namespace std;
 
int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
 
    int n, m;
    cin >> n >> m;
    vector<int> powers(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        ++powers[u - 1];
        ++powers[v - 1];
    }
 
    for (int i = 0; i < n; ++i)
        cout << powers[i] << ' ';
    cout << endl;
 
    return 0;
}
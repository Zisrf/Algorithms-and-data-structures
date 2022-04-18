#include <fstream>
#include <vector>
 
using namespace std;
 
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
 
    int n, m;
    fin >> n >> m;
    vector<int> powers(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        fin >> u >> v;
        ++powers[u - 1];
        ++powers[v - 1];
    }
 
    for (int i = 0; i < n; ++i)
        fout << powers[i] << ' ';
    fout << endl;
 
    return 0;
}
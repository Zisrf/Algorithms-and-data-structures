#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void topSort(int u, const vector<vector<int>> &g, vector<bool> &visited, vector<int> &ans)
{
    visited[u] = true;
    for (auto v : g[u])
        if (!visited[v])
            topSort(v, g, visited, ans);
    ans.push_back(u);
}

int main()
{
    ifstream cin("hamiltonian.in");
    ofstream cout("hamiltonian.out");

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
    }

    vector<int> ts;
    vector<bool> visited(n);
    for (int i = 0; i < n; ++i)
        if (!visited[i])
            topSort(i, g, visited, ts);
    reverse(ts.begin(), ts.end());

    for (int i = 0; i < n - 1; ++i)
        if (find(g[ts[i]].begin(), g[ts[i]].end(), ts[i + 1]) == g[ts[i]].end())
        {
            cout << "NO" << endl;
            return 0;
        }

    cout << "YES" << endl;

    cin.close();
    cout.close();
    return 0;
}
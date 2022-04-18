#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dp;
bool dfs(int u, const vector<vector<int>> &g, int parent = -1)
{
    if (dp[u] != -1)
        return dp[u];

    dp[u] = false;
    for (auto v : g[u])
        if (v != parent && dfs(v, g, u) == false)
        {
            dp[u] = true;
            break;
        }
    return dp[u];
}

int main()
{
    ifstream fin("game.in");
    ofstream fout("game.out");

    int n, m, start;
    fin >> n >> m >> start;
    --start;
    dp.resize(n, -1);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        fin >> u >> v;
        g[u - 1].push_back(v - 1);
    }

    if (dfs(start, g))
        fout << "First player wins" << endl;
    else
        fout << "Second player wins" << endl;

    return 0;
}
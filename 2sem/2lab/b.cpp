#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("cycle.in");
ofstream fout("cycle.out");

void dfs(int u, const vector<vector<int>> &g, vector<int> &color, vector<int> &path)
{
    color[u] = 1;
    path.push_back(u);
    for (auto v : g[u])
        if (color[v] == 1)
        {
            fout << "YES" << endl;
            int i = 0;
            while (path[i] != v)
                ++i;
            for (int j = i; j < path.size(); ++j)
                fout << path[j] + 1 << ' ';
            fout << endl;
            exit(0);
        }
        else if (color[v] == 0)
        {
            dfs(v, g, color, path);
        }
    path.pop_back();
    color[u] = 2;
}

int main()
{
    int n, m;
    fin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        fin >> u >> v;
        g[u - 1].push_back(v - 1);
    }

    vector<int> color(n);
    vector<int> path;
    for (int i = 0; i < n; ++i)
        if (color[i] == 0)
            dfs(i, g, color, path);

    fout << "NO" << endl;

    return 0;
}
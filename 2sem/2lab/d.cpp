#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("cond.in");
ofstream fout("cond.out");

void topSort(int u, const vector<vector<int>> &g, vector<bool> &visited, vector<int> &ans)
{
    visited[u] = true;
    for (auto v : g[u])
        if (!visited[v])
            topSort(v, g, visited, ans);
    ans.push_back(u);
}

void dfs(int u, const vector<vector<int>> &g, vector<int> &color, int curColor)
{
    color[u] = curColor;
    for (auto v : g[u])
        if (color[v] == 0)
            dfs(v, g, color, curColor);
}

int main()
{
    int n, m;
    fin >> n >> m;
    vector<vector<int>> g(n);
    vector<vector<int>> rg(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        fin >> u >> v;
        g[u - 1].push_back(v - 1);
        rg[v - 1].push_back(u - 1);
    }

    vector<int> topSortedList;
    vector<bool> visited(n);
    for (int i = 0; i < n; ++i)
        if (!visited[i])
            topSort(i, g, visited, topSortedList);
    reverse(topSortedList.begin(), topSortedList.end());

    int curColor = 1;
    vector<int> color(n);
    for (auto i = 0; i < n; ++i)
        if (color[topSortedList[i]] == 0)
        {
            dfs(topSortedList[i], rg, color, curColor);
            ++curColor;
        }

    fout << curColor - 1 << endl;
    for (int i = 0; i < n; ++i)
        fout << color[i] << ' ';
    fout << endl;

    return 0;
}
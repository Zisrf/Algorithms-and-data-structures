#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> g;
vector<vector<int>> dp;

void dfs(int u)
{
    dp[u][0] = 0;
    dp[u][1] = 1;
    for (auto v : g[u])
    {
        dfs(v);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

int main()
{
    int n;
    cin >> n;

    int root;
    g.resize(n);
    for (int i = 0; i < n; ++i)
    {
        int p;
        cin >> p;
        --p;
        if (p == -1)
            root = i;
        else
            g[p].push_back(i);
    }

    dp.resize(n, vector<int>(2));
    dfs(root);

    cout << max(dp[root][0], dp[root][1]) << endl;

    return 0;
}
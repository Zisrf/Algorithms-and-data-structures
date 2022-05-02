#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int M = 1e9;

vector<int> a;
vector<vector<int>> dp;

int f(int i, int j)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == j)
        dp[i][j] = 1;
    else if (a[i] != a[j])
        dp[i][j] = ((f(i + 1, j) + f(i, j - 1)) % M + M - f(i + 1, j - 1)) % M;
    else
        dp[i][j] = (f(i + 1, j) + f(i, j - 1) + 1) % M;

    return dp[i][j];
}

int main()
{
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    dp.resize(n, vector<int>(n, -1));

    cout << f(0, n - 1) << endl;

    return 0;
}
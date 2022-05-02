#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<long long>> dp;

long long f(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == 0 && j == 0)
        dp[i][j] = 1;
    else
        dp[i][j] = f(i - 2, j + 1) + f(i - 2, j - 1) + f(i - 1, j - 2) + f(i + 1, j - 2);
    return dp[i][j];
}

int main()
{
    ifstream fin("knight2.in");
    ofstream fout("knight2.out");

    fin >> n >> m;
    dp.resize(n, vector<long long>(m, -1));

    fout << f(n - 1, m - 1) << endl;

    return 0;
}
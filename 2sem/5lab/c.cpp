#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 2e9 + 11;

int main()
{
    string a, b;
    cin >> a >> b;

    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    string ans;
    int i = n;
    int j = m;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            ans.push_back(a[i - 1]);
            --i;
            --j;
        }
        else if (dp[i][j] == dp[i - 1][j])
        {
            --i;
        }
        else
        {
            --j;
        }
    }
    reverse(ans.begin(), ans.end());

    cout << ans << endl;

    return 0;
}
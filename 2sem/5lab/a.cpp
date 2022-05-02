#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> dp(n);
    vector<int> prev(n, -1);
    for (int i = 0; i < n; ++i)
    {
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
            if (a[j] < a[i] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
    }

    int maxi = 0;
    for (int i = 0; i < n; ++i)
        if (dp[i] > dp[maxi])
            maxi = i;

    vector<int> ans;
    int cur = maxi;
    while (cur != -1)
    {
        ans.push_back(cur);
        cur = prev[cur];
    }
    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << a[ans[i]] << ' ';
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 2e9 + 11;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> dp(n + 1, INF);
    vector<int> prev(n, -1);
    vector<int> last(n + 1, -1);

    dp[0] = -INF;
    for (int i = 0; i < n; ++i)
    {
        int j = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        last[j] = i;
        prev[i] = last[j - 1];
        dp[j] = a[i];
    }

    vector<int> ans;
    int i = n;
    while (dp[i] == INF)
        --i;

    i = last[i];
    while (i != -1)
    {
        ans.push_back(a[i]);
        i = prev[i];
    }
    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << ' ';
    cout << endl;

    return 0;
}
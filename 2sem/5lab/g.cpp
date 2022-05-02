#include <fstream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    ifstream fin("knapsack.in");
    ofstream fout("knapsack.out");
 
    int s, n;
    fin >> s >> n;
    vector<int> w(n);
    for (int i = 0; i < n; ++i)
        fin >> w[i];
 
    vector<bool> dp(s + 1);
 
    dp[0] = true;
    for (int i = 0; i < n; ++i)
    {
        for (int j = s; j >= 0; --j)
            if (j - w[i] >= 0 && dp[j - w[i]])
                dp[j] = true;
    }
 
    int ans = s;
    while (!dp[ans])
        --ans;
 
    fout << ans << endl;
 
    return 0;
}
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fin("turtle.in");
    ofstream fout("turtle.out");

    int w, h;
    fin >> h >> w;
    vector<vector<int>> cost(h, vector<int>(w));
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            fin >> cost[i][j];

    vector<vector<int>> dp(h, vector<int>(w));
    dp[h - 1][0] = cost[h - 1][0];
    for (int i = h - 2; i >= 0; --i)
        dp[i][0] = dp[i + 1][0] + cost[i][0];
    for (int j = 1; j < w; ++j)
        dp[h - 1][j] = dp[h - 1][j - 1] + cost[h - 1][j];
    for (int i = h - 2; i >= 0; --i)
        for (int j = 1; j < w; ++j)
            dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]) + cost[i][j];

    fout << dp[0][w - 1] << endl;
    
    return 0;
}
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
 
using namespace std;
 
const int INF = 2e9 + 11;
 
int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
 
    int n, m;
    cin >> n >> m;
 
    int start, finish;
    vector<vector<char>> map(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            cin >> map[i][j];
            if (map[i][j] == 'S')
                start = i * m + j;
            else if (map[i][j] == 'T')
                finish = i * m + j;
        }
 
    vector<vector<int>> g(n * m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (map[i][j] != '#')
            {
                if (i - 1 >= 0 && map[i - 1][j] != '#')
                    g[i * m + j].push_back((i - 1) * m + j);
                if (i + 1 < n && map[i + 1][j] != '#')
                    g[i * m + j].push_back((i + 1) * m + j);
                if (j - 1 >= 0 && map[i][j - 1] != '#')
                    g[i * m + j].push_back(i * m + j - 1);
                if (j + 1 < m && map[i][j + 1] != '#')
                    g[i * m + j].push_back(i * m + j + 1);
            }
 
    vector<int> dist(n * m, INF);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : g[u])
            if (dist[v] == INF)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
    }
 
    if (dist[finish] != INF)
    {
        cout << dist[finish] << endl;
    }
    else
    {
        cout << -1 << endl;
        return 0;
    }
 
    string ans;
    int cur = finish;
    while (cur != start)
        if (cur - m >= 0 && dist[cur] - 1 == dist[cur - m])
        {
            ans.push_back('D');
            cur -= m;
        }
        else if (cur + m < n * m && dist[cur] - 1 == dist[cur + m])
        {
            ans.push_back('U');
            cur += m;
        }
        else if (cur - 1 >= 0 && dist[cur] - 1 == dist[cur - 1])
        {
            ans.push_back('R');
            cur -= 1;
        }
        else if (cur + 1 < n * m && dist[cur] - 1 == dist[cur + 1])
        {
            ans.push_back('L');
            cur += 1;
        }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
 
    cin.close();
    cout.close();
    return 0;
}
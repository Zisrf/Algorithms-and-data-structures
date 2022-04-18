#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
 
using namespace std;
 
double dist(int x1, int y1, int x2, int y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
 
int main()
{
    ifstream cin("spantree.in");
    ofstream cout("spantree.out");
 
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
 
    double ans = 0;
    vector<bool> used(n);
    vector<double> d(n, INFINITY);
 
    d[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        int u = -1;
        for (int j = 0; j < n; ++j)
            if (!used[j] && (u == -1 || d[j] < d[u]))
                u = j;
        ans += d[u];
        used[u] = true;
        for (int v = 0; v < n; ++v)
            if (dist(x[u], y[u], x[v], y[v]) < d[v])
                d[v] = dist(x[u], y[u], x[v], y[v]);
    }
 
    cout << fixed << setprecision(3) << ans << endl;
 
    return 0;
}
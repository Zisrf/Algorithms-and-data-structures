#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define INF 2e9 + 11

bool isGood(double A, double A1, vector<double> &h)
{
    int n = h.size();
    h[0] = A;
    h[1] = A1;
    for (int i = 2; i < n; ++i)
        h[i] = 2 * h[i - 1] + 2 - h[i - 2];
    for (int i = 0; i < n; ++i)
        if (h[i] < 0)
            return false;
    return true;
}

int main()
{
    ifstream cin("garland.in");
    ofstream cout("garland.out");
    cout.precision(16);

    int n;
    double A;
    cin >> n >> A;

    vector<double> h(n);
    double l = 0;
    double r = A;
    while ((r - l) > 1e-7)
    {
        double m = (l + r) / 2;
        if (isGood(A, m, h))
            r = m;
        else
            l = m;
    }

    isGood(A, r, h);
    cout << h[n - 1] << endl;

    return 0;
}
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int firstIn(const vector<int> &a, int k)
{
    int l = -1;
    int r = a.size() - 1;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (a[m] >= k)
            r = m;
        else
            l = m;
    }
    if (a[r] == k)
        return r;
    else
        return -2;
}

int lastIn(const vector<int> &a, int k)
{
    int l = 0;
    int r = a.size();
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (a[m] <= k)
            l = m;
        else
            r = m;
    }
    if (a[l] == k)
        return l;
    else
        return -2;
}

int main()
{
    ifstream cin("binsearch.in");
    ofstream cout("binsearch.out");

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int m, k;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> k;
        cout << firstIn(a, k) + 1 << ' ' << lastIn(a, k) + 1 << endl;
    }

    cin.close();
    cout.close();
    return 0;
}
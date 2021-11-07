// Doesn't work (WA4)

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int maxInd(const vector<int> &a, int l, int r)
{
    if (a.size() == 0)
        return -1;
    int res = l;
    for (int i = l + 1; i <= r; ++i)
        if (a[res] < a[i])
            res = i;
    return res;
}

void antiQS(vector<int> &a, int l, int r)
{
    if (r - l <= 1)
        return;
    int m = (l + r) / 2;
    int maxIndex = maxInd(a, l, r);
    int maxElem = a[maxIndex];
    a.erase(a.begin() + maxIndex);
    a.insert(a.begin() + m, maxElem);
    antiQS(a, l, m - 1);
    antiQS(a, m + 1, r);
}

int main()
{
    ifstream cin("antiqs.in");
    ofstream cout("antiqs.out");

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        a[i] = i + 1;

    antiQS(a, 0, n - 1);

    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    cout << endl;

    cin.close();
    cout.close();
    return 0;
}
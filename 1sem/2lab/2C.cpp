#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long long ans = 0;

bool isSorted(const vector<int> &a)
{
    for (int i = 1; i < a.size(); ++i)
        if (a[i - 1] > a[i])
            return false;
    return true;
}

void merge(vector<int> &res, const vector<int> &a, const vector<int> &b)
{
    res.clear();
    res.reserve(a.size() + b.size());
    int i = 0, j = 0;
    while (i < a.size() || j < b.size())
    {
        if (i == a.size())
        {
            res.push_back(b[j]);
            ++j;
        }
        else if (j == b.size())
        {
            res.push_back(a[i]);
            ++i;
        }
        else if (a[i] <= b[j])
        {
            res.push_back(a[i]);
            ++i;
        }
        else
        {
            res.push_back(b[j]);
            ans += a.size() - i;
            ++j;
        }
    }
}

void mergeSort(vector<int> &a)
{
    if (isSorted(a))
        return;
    int m = a.size() / 2;
    vector<int> l(a.begin(), a.begin() + m);
    vector<int> r(a.begin() + m, a.end());
    mergeSort(l);
    mergeSort(r);
    merge(a, l, r);
}

int main()
{
    ifstream cin("inversions.in");
    ofstream cout("inversions.out");

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    mergeSort(a);

    cout << ans << endl;

    cin.close();
    cout.close();
    return 0;
}
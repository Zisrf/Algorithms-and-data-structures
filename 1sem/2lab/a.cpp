#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool isSorted(const vector<int> &a)
{
    for (int i = 0; i < a.size() - 1; ++i)
        if (a[i] > a[i + 1])
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
            res.push_back(b[j++]);
        else if (j == b.size())
            res.push_back(a[i++]);
        else if (a[i] < b[j])
            res.push_back(a[i++]);
        else
            res.push_back(b[j++]);
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
    ifstream cin("sort.in");
    ofstream cout("sort.out");

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    mergeSort(a);

    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    cout << '\n';

    cin.close();
    cout.close();
    return 0;
}
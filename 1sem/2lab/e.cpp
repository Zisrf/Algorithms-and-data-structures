#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int QSort(vector<int> &a, int l, int r, int k)
{
    int i = l, j = r;
    int m = a[(l + r) / 2];
    do
    {
        while (a[i] < m)
            ++i;
        while (a[j] > m)
            --j;
        if (i <= j)
        {
            swap(a[i], a[j]);
            ++i;
            --j;
        }
    } while (i <= j);
    if (l <= j && l <= k && k <= j)
        QSort(a, l, j, k);
    else if (i <= r && i <= k && k <= r)
        QSort(a, i, r, k);
    return a[k];
}

int main()
{
    ifstream fin("kth.in");
    ofstream fout("kth.out");

    int n, k;
    int A, B, C, a0, a1;
    fin >> n >> k;
    fin >> A >> B >> C >> a0 >> a1;
    vector<int> a(n);
    if (n > 0)
        a[0] = a0;
    if (n > 1)
        a[1] = a1;
    for (int i = 2; i < n; ++i)
        a[i] = A * a[i - 2] + B * a[i - 1] + C;

    fout << QSort(a, 0, n - 1, k - 1) << endl;

    return 0;
}
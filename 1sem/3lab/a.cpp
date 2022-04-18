#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool isHeap(const vector<int> &a)
{
    for (int i = 0; i < a.size(); ++i)
        if (2 * i + 1 < a.size() && a[i] > a[2 * i + 1] || 2 * i + 2 < a.size() && a[i] > a[2 * i + 2])
            return false;
    return true;
}

int main()
{
    ifstream fin("isheap.in");
    ofstream fout("isheap.out");

    int n;
    fin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        fin >> a[i];

    if (isHeap(a))
        fout << "YES\n";
    else
        fout << "NO\n";

    return 0;
}
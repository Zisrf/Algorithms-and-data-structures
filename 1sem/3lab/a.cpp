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
    ifstream cin("isheap.in");
    ofstream cout("isheap.out");

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    if (isHeap(a))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fin("antiqs.in");
    ofstream fout("antiqs.out");

    int n;
    fin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        a[i] = i + 1;

    for (int i = 1; i < n; ++i)
        swap(a[i], a[i / 2]);

    for (int i = 0; i < n; ++i)
        fout << a[i] << ' ';
    fout << endl;

    return 0;
}
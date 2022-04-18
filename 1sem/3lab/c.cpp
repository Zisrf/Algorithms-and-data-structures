#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void countingSort(vector<string> &s, int t)
{
    vector<string> res(s.size());
    vector<int> c('z' + 1, 0);
    for (int i = 0; i < s.size(); ++i)
        ++c[s[i][t]];
    for (int i = 'b'; i <= 'z'; ++i)
        c[i] += c[i - 1];
    for (int i = s.size() - 1; i >= 0; --i)
        res[--c[s[i][t]]] = s[i];
    s = res;
}

void radixSort(vector<string> &s, int k)
{
    for (int i = 0; i < k; ++i)
        countingSort(s, s[0].size() - 1 - i);
}

int main()
{
    ifstream fin("radixsort.in");
    ofstream fout("radixsort.out");

    int n, m, k;
    fin >> n >> m >> k;
    vector<string> s(n);
    for (int i = 0; i < n; ++i)
        fin >> s[i];

    radixSort(s, k);

    for (int i = 0; i < n; ++i)
        fout << s[i] << endl;

    return 0;
}
#include <fstream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<int> H;
int h(int i, const vector<int> &k, const vector<int> &l, const vector<int> &r)
{
    if (i == -1)
        return 0;
    if (H[i] != -1)
        return H[i];
    return H[i] = 1 + max(h(l[i], k, l, r), h(r[i], k, l, r));
}
 
int main()
{
    ifstream fin("balance.in");
    ofstream fout("balance.out");
 
    int n;
    fin >> n;
    vector<int> k(n), l(n), r(n);
    H.resize(n, -1);
    for (int i = 0; i < n; ++i)
    {
        fin >> k[i] >> l[i] >> r[i];
        --l[i];
        --r[i];
    }
 
    for (int i = 0; i < n; ++i)
        fout << h(r[i], k, l, r) - h(l[i], k, l, r) << endl;
        
    return 0;
}
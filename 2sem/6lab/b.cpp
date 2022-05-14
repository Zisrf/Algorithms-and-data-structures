#include <fstream>
#include <vector>
#include <string>

using namespace std;

const int M = 2e9 + 11;
const int P = 251;

vector<int> h;
vector<int> p;

void init_hash(const string &s)
{
    h.resize(s.size());
    p.resize(s.size());
    h[0] = s[0];
    p[0] = 1;
    for (int i = 1; i < s.size(); ++i)
    {
        h[i] = (1ll * h[i - 1] * P % M + s[i]) % M;
        p[i] = (1ll * p[i - 1] * P) % M;
    }
}

int get_hash(int i, int j)
{
    if (i == 0)
        return h[j];
    return (h[j] - 1ll * h[i - 1] * p[j - i + 1] % M + M) % M;
}

int main()
{
    ifstream fin("search2.in");
    ofstream fout("search2.out");

    string s1, s2;
    fin >> s1;
    fin >> s2;

    int t = s1[0];
    for (int i = 1; i < s1.size(); ++i)
        t = (1ll * t * P % M + s1[i]) % M;
    init_hash(s2);

    vector<int> ans;
    for (int i = 0; i + s1.size() <= s2.size(); ++i)
        if (t == get_hash(i, i + s1.size() - 1))
            ans.push_back(i);

    fout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        fout << ans[i] + 1 << ' ';
    fout << endl;

    return 0;
}
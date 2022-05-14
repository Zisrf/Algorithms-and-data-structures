#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ifstream fin("search1.in");
    ofstream fout("search1.out");

    string p, t;
    fin >> p;
    fin >> t;

    vector<int> ans;
    for (int i = 0; i + p.size() <= t.size(); ++i)
        if (p == t.substr(i, p.size()))
            ans.push_back(i);

    fout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        fout << ans[i] + 1 << ' ';
    fout << endl;

    return 0;
}
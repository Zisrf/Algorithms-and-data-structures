#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ifstream fin("prefix.in");
    ofstream fout("prefix.out");

    string s;
    fin >> s;

    vector<int> p(s.size());
    for (int i = 1; i < p.size(); ++i)
    {
        int k = p[i - 1];
        while (k > 0 && s[i] != s[k])
            k = p[k - 1];
        if (s[i] == s[k])
            ++k;
        p[i] = k;
    }

    for (int i = 0; i < p.size(); ++i)
        fout << p[i] << ' ';
    fout << endl;

    return 0;
}
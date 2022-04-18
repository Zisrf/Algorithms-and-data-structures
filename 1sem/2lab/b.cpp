#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Member
{
    string country, name;
};

bool isSorted(const vector<Member> &a)
{
    for (int i = 1; i < a.size(); ++i)
        if (a[i - 1].country > a[i].country)
            return false;
    return true;
}

void merge(vector<Member> &res, const vector<Member> &a, const vector<Member> &b)
{
    res.clear();
    res.reserve(a.size() + b.size());
    int i = 0, j = 0;
    while (i < a.size() || j < b.size())
        if (i == a.size())
            res.push_back(b[j++]);
        else if (j == b.size())
            res.push_back(a[i++]);
        else if (a[i].country <= b[j].country)
            res.push_back(a[i++]);
        else
            res.push_back(b[j++]);
}

void mergeSort(vector<Member> &a)
{
    if (isSorted(a))
        return;
    int m = a.size() / 2;
    vector<Member> l(a.begin(), a.begin() + m);
    vector<Member> r(a.begin() + m, a.end());
    mergeSort(l);
    mergeSort(r);
    merge(a, l, r);
}

int main()
{
    ifstream cin("race.in");
    ofstream cout("race.out");

    int n;
    cin >> n;
    vector<Member> members(n);
    for (int i = 0; i < n; ++i)
        cin >> members[i].country >> members[i].name;

    mergeSort(members);

    string curCountry = "";
    for (int i = 0; i < n; ++i)
    {
        if (members[i].country != curCountry)
        {
            cout << "=== " << members[i].country << " ===\n";
            curCountry = members[i].country;
        }
        cout << members[i].name << '\n';
    }

    return 0;
}
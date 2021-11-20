#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 2e9 + 11;

vector<int> minMem;
int min(int i, const vector<int> &k, const vector<int> &l, const vector<int> &r)
{
    if (i == -1)
        return INF;
    if (minMem[i] != INF)
        return minMem[i];
    return minMem[i] = min({k[i], min(l[i], k, l, r), min(r[i], k, l, r)});
}

vector<int> maxMem;
int max(int i, const vector<int> &k, const vector<int> &l, const vector<int> &r)
{
    if (i == -1)
        return -INF;
    if (maxMem[i] != -INF)
        return maxMem[i];
    return maxMem[i] = max({k[i], max(l[i], k, l, r), max(r[i], k, l, r)});
}

vector<int> isCorMem;
bool isCorrect(int i, const vector<int> &k, const vector<int> &l, const vector<int> &r)
{
    if (i == -1)
        return true;
    if (isCorMem[i] != -1)
        return isCorMem[i];
    if (!isCorrect(l[i], k, l, r) || !isCorrect(r[i], k, l, r))
        return isCorMem[i] = false;
    return isCorMem[i] = (k[i] > max(l[i], k, l, r) && k[i] < min(r[i], k, l, r));
}

int main()
{
    ifstream cin("check.in");
    ofstream cout("check.out");

    int n;
    cin >> n;
    minMem.resize(n, INF);
    maxMem.resize(n, -INF);
    isCorMem.resize(n, -1);
    vector<int> k(n), l(n), r(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> k[i] >> l[i] >> r[i];
        --l[i];
        --r[i];
    }

    bool isTreeCorrect = true;
    for (int i = 0; i < n; ++i)
        if (!isCorrect(i, k, l, r))
        {
            isTreeCorrect = false;
            break;
        }

    if (isTreeCorrect)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    cin.close();
    cout.close();
    return 0;
}
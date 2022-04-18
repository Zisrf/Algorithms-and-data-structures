#include <fstream>
#include <vector>
#include <string>
#include <list>
#include <cmath>
 
using namespace std;
 
struct Set
{
    static const int MOD = 1e6 + 3;
    vector<list<int>> hashTable;
    Set()
    {
        hashTable.resize(MOD);
    }
    ~Set()
    {
        hashTable.clear();
    }
    static int getHash(int x)
    {
        return abs(x) % MOD;
    }
    bool exists(int x)
    {
        for (auto i : hashTable[getHash(x)])
            if (i == x)
                return true;
        return false;
    }
    void insert(int x)
    {
        if (!exists(x))
            hashTable[getHash(x)].push_back(x);
    }
    void erase(int x)
    {
        if (exists(x))
        {
            auto pos = hashTable[getHash(x)].begin();
            while (pos != hashTable[getHash(x)].end())
            {
                if (*pos == x)
                    break;
                ++pos;
            }
            hashTable[getHash(x)].erase(pos);
        }
    }
};
 
int main()
{
    ifstream cin("set.in");
    ofstream cout("set.out");
 
    Set s;
    string cmd;
    int x;
    while (cin >> cmd >> x)
    {
        if (cmd == "insert")
        {
            s.insert(x);
        }
        else if (cmd == "delete")
        {
            s.erase(x);
        }
        else
        {
            if (s.exists(x))
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
    }
 
    return 0;
}
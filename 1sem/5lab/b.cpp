#include <fstream>
#include <vector>
#include <string>
#include <list>
#include <cmath>
 
using namespace std;
 
struct Map
{
    vector<list<pair<string, string>>> hashTable;
    static const int M = 1e6 + 3;
    static const int P = 43;
    Map()
    {
        hashTable.resize(M);
    }
    ~Map()
    {
        hashTable.clear();
    }
    int getHash(const string &key)
    {
        int res = 0;
        for (int i = 0; i < key.size(); ++i)
            res = (res * P + key[i] - 'a' + M) % M;
        return res;
    }
    list<pair<string, string>>::iterator find(const string &key)
    {
        int hash = getHash(key);
        for (auto it = hashTable[hash].begin(); it != hashTable[hash].end(); ++it)
            if (it->first == key)
                return it;
        return hashTable[hash].end();
    }
    void insert(const string &key, const string &value)
    {
        int hash = getHash(key);
        auto pos = find(key);
        if (pos == hashTable[hash].end())
            hashTable[hash].push_back({key, value});
        else
            pos->second = value;
    }
    void erase(const string &key)
    {
        int hash = getHash(key);
        auto pos = find(key);
        if (pos != hashTable[hash].end())
            hashTable[hash].erase(pos);
    }
    string get(const string &key)
    {
        int hash = getHash(key);
        auto pos = find(key);
        if (pos == hashTable[hash].end())
            return "none";
        else
            return pos->second;
    }
};
 
int main()
{
    ifstream fin("map.in");
    ofstream fout("map.out");
 
    string cmd, key, value;
    Map m;
    while (fin >> cmd)
    {
        if (cmd == "put")
        {
            fin >> key >> value;
            m.insert(key, value);
        }
        else if (cmd == "delete")
        {
            fin >> key;
            m.erase(key);
        }
        else
        {
            fin >> key;
            fout << m.get(key) << endl;
        }
    }

    return 0;
}
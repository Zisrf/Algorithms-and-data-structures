#include <fstream>
#include <vector>
#include <string>
#include <cmath>
 
using namespace std;
 
struct Node
{
    string key;
    string value;
    Node *prev;
    Node *next;
    Node(const string &_key, const string &_value = "")
    {
        key = _key;
        value = _value;
        prev = nullptr;
        next = nullptr;
    }
};
 
struct LinkedMap
{
    vector<vector<Node *>> hashTable;
    Node *last = nullptr;
    const int M = 1e6 + 3;
    const int P = 43;
    LinkedMap()
    {
        hashTable.resize(M);
    }
    int getHash(const string &key)
    {
        int res = 0;
        for (int i = 0; i < key.size(); ++i)
            res = (res * P + key[i] - 'a' + M) % M;
        return res;
    }
    int find(const string &key)
    {
        int h = getHash(key);
        for (int i = 0; i < hashTable[h].size(); ++i)
            if (hashTable[h][i]->key == key)
                return i;
        return hashTable[h].size();
    }
    void insert(const string &key, const string &value)
    {
        int h = getHash(key);
        int pos = find(key);
        if (pos == hashTable[h].size())
        {
            Node *tmp = new Node(key, value);
            hashTable[h].push_back(tmp);
            hashTable[h][pos]->prev = last;
            if (last != nullptr)
                last->next = hashTable[h][pos];
            last = hashTable[h][pos];
            return;
        }
        hashTable[h][pos]->value = value;
    }
    void erase(const string &key)
    {
        int h = getHash(key);
        int pos = find(key);
        if (pos == hashTable[h].size())
            return;
        if (hashTable[h][pos]->next != nullptr)
            hashTable[h][pos]->next->prev = hashTable[h][pos]->prev;
        if (hashTable[h][pos]->prev != nullptr)
            hashTable[h][pos]->prev->next = hashTable[h][pos]->next;
        if (last == hashTable[h][pos])
            last = last->prev;
        delete hashTable[h][pos];
        hashTable[h].erase(hashTable[h].begin() + pos);
    }
    string get(const string &key)
    {
        int h = getHash(key);
        int pos = find(key);
        if (pos == hashTable[h].size())
            return "none";
        return hashTable[h][pos]->value;
    }
    string prev(const string &key)
    {
        int h = getHash(key);
        int pos = find(key);
        if (pos == hashTable[h].size() || hashTable[h][pos]->prev == nullptr)
            return "none";
        return hashTable[h][pos]->prev->value;
    }
    string next(const string &key)
    {
        int h = getHash(key);
        int pos = find(key);
        if (pos == hashTable[h].size() || hashTable[h][pos]->next == nullptr)
            return "none";
        return hashTable[h][pos]->next->value;
    }
};
 
int main()
{
    ifstream cin("linkedmap.in");
    ofstream cout("linkedmap.out");
 
    string cmd, key, value;
    LinkedMap m;
    while (cin >> cmd)
    {
        if (cmd == "put")
        {
            cin >> key >> value;
            m.insert(key, value);
        }
        else if (cmd == "delete")
        {
            cin >> key;
            m.erase(key);
        }
        else if (cmd == "get")
        {
            cin >> key;
            cout << m.get(key) << endl;
        }
        else if (cmd == "prev")
        {
            cin >> key;
            cout << m.prev(key) << endl;
        }
        else
        {
            cin >> key;
            cout << m.next(key) << endl;
        }
    }

    return 0;
}
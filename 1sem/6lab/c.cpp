#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 2e9 + 11;

struct node
{
    int value;
    node *left;
    node *right;
    node *parent;
    node(int _value)
    {
        value = _value;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
    ~node()
    {
        delete left;
        delete right;
    }
};

bool exists(node *root, int v)
{
    if (root == nullptr)
        return false;
    if (v == root->value)
        return true;
    if (v > root->value)
        return exists(root->right, v);
    return exists(root->left, v);
}

node *min(node *root)
{
    if (root == nullptr)
        return nullptr;
    if (root->left == nullptr)
        return root;
    return min(root->left);
}

node *max(node *root)
{
    if (root == nullptr)
        return nullptr;
    if (root->right == nullptr)
        return root;
    return max(root->right);
}

node *insert(node *root, int v)
{
    if (root == nullptr)
    {
        root = new node(v);
        return root;
    }
    if (v < root->value && root->left == nullptr)
    {
        root->left = new node(v);
        root->left->parent = root;
        return root;
    }
    if (v > root->value && root->right == nullptr)
    {
        root->right = new node(v);
        root->right->parent = root;
        return root;
    }
    if (v < root->value)
    {
        insert(root->left, v);
        return root;
    }
    else
    {
        insert(root->right, v);
        return root;
    }
}

node *erase(node *root, int v)
{
    if (v < root->value)
    {
        root->left = erase(root->left, v);
        return root;
    }
    if (v > root->value)
    {
        root->right = erase(root->right, v);
        return root;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        delete root;
        return nullptr;
    }
    if (root->right == nullptr)
    {
        auto newRoot = root->left;
        root->left = nullptr;
        delete root;
        return newRoot;
    }
    if (root->left == nullptr)
    {
        auto newRoot = root->right;
        root->right = nullptr;
        delete root;
        return newRoot;
    }
    auto delRoot = min(root->right);
    auto delRootValue = delRoot->value;
    erase(root, delRootValue);
    root->value = delRootValue;
    return root;
}

int prev(node *root, int v)
{
    if (root == nullptr)
        return INF;
    if (root->value < v && (root->right == nullptr || min(root->right)->value >= v))
        return root->value;
    if (root->value >= v)
        return prev(root->left, v);
    return prev(root->right, v);
}

int next(node *root, int v)
{
    if (root == nullptr)
        return INF;
    if (root->value > v && (root->left == nullptr || max(root->left)->value <= v))
        return root->value;
    if (root->value <= v)
        return next(root->right, v);
    return next(root->left, v);
}

int main()
{
    ifstream fin("bstsimple.in");
    ofstream fout("bstsimple.out");

    node *root = nullptr;
    string command;
    int arg;
    while (fin >> command >> arg)
    {
        if (command == "insert")
        {
            if (!exists(root, arg))
                root = insert(root, arg);
        }
        else if (command == "delete")
        {
            if (exists(root, arg))
                root = erase(root, arg);
        }
        else if (command == "exists")
        {
            if (exists(root, arg))
                fout << "true" << endl;
            else
                fout << "false" << endl;
        }
        else if (command == "prev")
        {
            int ans = prev(root, arg);
            if (ans == INF)
                fout << "none" << endl;
            else
                fout << ans << endl;
        }
        else if (command == "next")
        {
            int ans = next(root, arg);
            if (ans == INF)
                fout << "none" << endl;
            else
                fout << ans << endl;
        }
    }

    delete root;
    return 0;
}
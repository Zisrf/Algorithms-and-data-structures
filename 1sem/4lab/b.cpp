#include <iostream>
#include <fstream>

using namespace std;

struct node
{
    int value;
    node *prev;
    node *next;
    node(int _value = 0)
    {
        value = _value;
        prev = nullptr;
        next = nullptr;
    }
};

struct Queue
{
    node *first;
    node *last;
    Queue()
    {
        first = nullptr;
        last = nullptr;
    }
    ~Queue()
    {
        if (first->next != nullptr)
            delete first->next;
        delete first;
    }
    int size()
    {
        int res = 0;
        node *i = first;
        while (i != nullptr)
        {
            ++res;
            i = i->next;
        }
        return res;
    }
    void push(int val)
    {
        node *newNode = new node(val);
        if (this->size() == 0)
        {
            first = last = newNode;
        }
        else
        {
            newNode->prev = last;
            last->next = newNode;
            last = newNode;
        }
    }
    int pop()
    {
        int res = first->value;
        node *tmp = first;
        first = first->next;
        delete tmp;
        if (first != nullptr)
            first->prev = nullptr;
        return res;
    }
};

int main()
{
    ifstream fin("queue.in");
    ofstream fout("queue.out");

    Queue q;
    char mode;
    int n, val;
    fin >> n;
    for (int i = 0; i < n; ++i)
    {
        fin >> mode;
        if (mode == '+')
        {
            fin >> val;
            q.push(val);
        }
        else
        {
            fout << q.pop() << endl;
        }
    }

    return 0;
}
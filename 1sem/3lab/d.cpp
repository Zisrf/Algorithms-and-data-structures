#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int INF = 2e9 + 11;

int parent(int i)
{
    return (i - 1) / 2;
}

int leftChild(int i)
{
    return 2 * i + 1;
}

int rightChild(int i)
{
    return 2 * i + 2;
}

void minHeapify(vector<int> &a, int i)
{
    int l = leftChild(i);
    int r = rightChild(i);
    int mini = i;
    if (l < a.size() && a[l] < a[mini])
        mini = l;
    if (r < a.size() && a[r] < a[mini])
        mini = r;
    if (mini != i)
    {
        swap(a[i], a[mini]);
        minHeapify(a, mini);
    }
}

void buildMinHeap(vector<int> &a)
{
    for (int i = a.size() / 2; i >= 0; --i)
        minHeapify(a, i);
}

struct PrQueue
{
    vector<int> heap;
    int decreaseKey(int i, int key)
    {
        heap[i] = key;
        while (i > 0 && heap[parent(i)] > heap[i])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
        return i;
    }
    int push(int key)
    {
        heap.push_back(INF);
        return this->decreaseKey(heap.size() - 1, key);
    }
    int extractMin()
    {
        if (heap.size() == 0)
            return INF;
        int res = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        minHeapify(heap, 0);
        return res;
    }
    int find(int x)
    {
        for (int i = 0; i < heap.size(); ++i)
            if (heap[i] == x)
                return i;
        return INF;
    }
};

int main()
{
    ifstream cin("priorityqueue.in");
    ofstream cout("priorityqueue.out");

    PrQueue pq;
    vector<int> arrayThatContainsHistoryOfOperationsWithHeap;
    string mode;
    while (cin >> mode)
    {
        if (mode == "push")
        {
            int x;
            cin >> x;
            pq.push(x);
            arrayThatContainsHistoryOfOperationsWithHeap.push_back(x);
        }
        else if (mode == "extract-min")
        {
            int ans = pq.extractMin();
            if (ans == INF)
                cout << '*' << endl;
            else
                cout << ans << endl;
            arrayThatContainsHistoryOfOperationsWithHeap.push_back(INF);
        }
        else if (mode == "decrease-key")
        {
            int x, y;
            cin >> x >> y;
            pq.decreaseKey(pq.find(arrayThatContainsHistoryOfOperationsWithHeap[x - 1]), y);
            arrayThatContainsHistoryOfOperationsWithHeap[x - 1] = y;
            arrayThatContainsHistoryOfOperationsWithHeap.push_back(INF);
        }
    }

    return 0;
}
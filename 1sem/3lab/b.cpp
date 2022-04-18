#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void maxHeapify(vector<int> &a, int i, int heapSize)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int maxi = i;
    if (l < heapSize && a[maxi] < a[l])
        maxi = l;
    if (r < heapSize && a[maxi] < a[r])
        maxi = r;
    if (maxi != i)
    {
        swap(a[i], a[maxi]);
        maxHeapify(a, maxi, heapSize);
    }
}

void buildMaxHeap(vector<int> &a)
{
    int heapSize = a.size();
    for (int i = a.size() / 2; i >= 0; --i)
        maxHeapify(a, i, heapSize);
}

void heapSort(vector<int> &a)
{
    buildMaxHeap(a);
    int heapSize = a.size();
    for (int i = a.size() - 1; i >= 1; --i)
    {
        swap(a[0], a[i]);
        --heapSize;
        maxHeapify(a, 0, heapSize);
    }
}

int main()
{
    ifstream fin("sort.in");
    ofstream fout("sort.out");

    int n;
    fin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        fin >> a[i];

    heapSort(a);

    for (int i = 0; i < n; ++i)
        fout << a[i] << ' ';
    fout << endl;

    return 0;
}
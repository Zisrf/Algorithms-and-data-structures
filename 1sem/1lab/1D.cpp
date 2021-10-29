#include <fstream>
#include <vector>

using namespace std;

void smallSort(int *begin, int *end)
{
    int *a = begin;
    int n = end - begin;
    bool isSorted = false;
    for (int i = 0; i < n; ++i)
    {
        isSorted = true;
        for (int j = 0; j < n - 1; ++j)
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                isSorted = false;
            }
        if (isSorted)
            break;
    }
}

int main()
{
    ifstream fin("smallsort.in");
    ofstream fout("smallsort.out");
    int numbers[10000];
    int n;
    fin >> n;
    for (int i = 0; i < n; ++i)
        fin >> numbers[i];
    smallSort(numbers, numbers + n);
    for (int i = 0; i < n; ++i)
        fout << numbers[i] << ' ';
    fout << endl;
    return 0;
}
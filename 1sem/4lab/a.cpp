#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Stack
{
    void *arr;
    size_t width, curSize, size;
    Stack(size_t elemSize = 1)
    {
        width = elemSize;
        arr = malloc(width);
        size = 1;
        curSize = 0;
    }
    void *push(void *newElem)
    {
        if (curSize == size)
        {
            arr = realloc(arr, 2 * size * width);
            size *= 2;
        }
        memcpy((char *)arr + width * curSize, newElem, width);
        ++curSize;
    }
    void *pop()
    {
        if (curSize == 0)
            return NULL;
        --curSize;
        return (char *)arr + curSize * width;
    }
};

int main()
{
    ifstream fin("stack.in");
    ofstream fout("stack.out");

    Stack st(sizeof(int));
    char mode;
    int n, elem;
    fin >> n;
    for (int i = 0; i < n; ++i)
    {
        fin >> mode;
        if (mode == '+')
        {
            fin >> elem;
            st.push(&elem);
        }
        else
        {
            fout << *((int *)st.pop()) << endl;
        }
    }

    free(st.arr);
    return 0;
}
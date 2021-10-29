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
    size_t Size()
    {
        return curSize;
    }
    void *top()
    {
        if (curSize == 0)
            return NULL;
        return (char *)arr + width * (curSize - 1);
    }
};

int main()
{
    ifstream cin("postfix.in");
    ofstream cout("postfix.out");

    Stack st(sizeof(int));
    char c;
    while (cin >> c)
    {
        if (c == '+')
        {
            int b = *((int *)st.pop());
            int a = *((int *)st.pop());
            int res = a + b;
            st.push(&res);
        }
        else if (c == '-')
        {
            int b = *((int *)st.pop());
            int a = *((int *)st.pop());
            int res = a - b;
            st.push(&res);
        }
        else if (c == '*')
        {
            int b = *((int *)st.pop());
            int a = *((int *)st.pop());
            int res = a * b;
            st.push(&res);
        }
        else
        {
            int res = c - '0';
            st.push(&res);
        }
    }

    cout << *((int *)st.top()) << endl;

    free(st.arr);
    cin.close();
    cout.close();
    return 0;
}
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

bool isPair(char a, char b)
{
    return a == '(' && b == ')' || a == '[' && b == ']';
}

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
    ifstream cin("brackets.in");
    ofstream cout("brackets.out");

    Stack st;
    string s;
    while (cin >> s)
    {
        st = Stack(sizeof(char));
        for (auto c : s)
            if (st.Size() > 0 && isPair(*((char *)st.top()), c))
                st.pop();
            else
                st.push(&c);
        if (st.Size() == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        free(st.arr);
    }

    cin.close();
    cout.close();
    return 0;
}
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("aplusbb.in");
    ofstream fout("aplusbb.out");

    long long a, b;
    fin >> a >> b;

    fout << a + b * b << endl;
    
    return 0;
}
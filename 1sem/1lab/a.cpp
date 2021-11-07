#include <fstream>

using namespace std;

int main()
{
    ifstream fin("aplusb.in");
    ofstream fout("aplusb.out");
    int a, b;
    fin >> a >> b;
    fout << a + b << endl;
    return 0;
}
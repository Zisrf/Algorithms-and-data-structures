#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void qSort(vector<pair<double, int>> &nums)
{
    bool isSorted;
    for (int i = 0; i < nums.size(); ++i)
    {
        isSorted = true;
        for (int j = 0; j < nums.size() - 1; ++j)
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                isSorted = false;
            }
        if (isSorted)
            break;
    }
}

int main()
{
    ifstream fin("sortland.in");
    ofstream fout("sortland.out");

    int n;
    fin >> n;
    vector<pair<double, int>> nums(n);
    for (int i = 0; i < n; ++i)
    {
        fin >> nums[i].first;
        nums[i].second = i;
    }

    qSort(nums);

    fout << nums[0].second + 1 << ' ';
    fout << nums[n / 2].second + 1 << ' ';
    fout << nums[n - 1].second + 1 << endl;

    return 0;
}
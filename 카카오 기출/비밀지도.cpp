#include <vector>
#include <string>
#include <bitset>

using namespace std;
vector<string> result;

void solution(int n, vector<int> arr1, vector<int> arr2)
{
    string preset;
    for (int i = 0; i < n; i++)
    {
        preset += ' ';
    }
    result.assign(n, preset);

    for (int i = 0; i < arr1.size(); i++)
    {
        bitset<16> bit1(arr1[i]);
        bitset<16> bit2(arr2[i]);
        for (int j = 0; j < n; j++)
        {
            if (bit1.test(j) || bit2.test(j))
            {
                result[i][n - j - 1] = '#';
            }
        }
    }
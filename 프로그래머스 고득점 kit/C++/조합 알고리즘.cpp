#include <string>
#include <vector>
#include <iostream>

using namespace std;
void combination(vector<int> arr, vector<bool> check, int idx, int n, int r)
{
    if (n == r)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (check[i] == true)
                cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    else
    {
        for (int i = idx; i < arr.size(); i++)
        {
            if (check[i])
                continue;
            check[i] = true;
            combination(arr, check, i, n + 1, r);
            check[i] = false;
        }
    }
}

int solution(string numbers)
{
    vector<int> arr = {1, 2, 3, 4};
    vector<bool> check(4);
    combination(arr, check, 0, 0, 2);
    return -1;
}
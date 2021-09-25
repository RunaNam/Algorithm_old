#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> v;

void permutation(bool *arr, int idx, int size, int r)
{
    if (idx == r)
    {
        for (int i = 0; i < r; i++)
        {
            cout << v[i];
        }
        cout << '\n';
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i])
                continue;
            arr[i] = true;
            v.push_back(i + 1);
            permutation(arr, idx + 1, size, r);
            v.pop_back();
            arr[i] = false;
        }
    }
}

int solution(string numbers)
{
    int answer = 0;
    bool arr[4] = {
        false,
    };
    permutation(arr, 0, 4, 2);
    return -1;
}
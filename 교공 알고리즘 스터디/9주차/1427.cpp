
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
string s;
vector<char> v;

// 퀵소트
int partition(int l, int r)
{
    int pivot = v[l] - '0';
    int low = l + 1;
    int high = r;

    while (low <= high)
    {
        while (low <= r && pivot >= (v[low] - '0'))
        { // 피벗보다 큰값 찾기
            low++;
        }
        while (high >= (l + 1) && pivot <= (v[high] - '0'))
        { // 피벗보다 작은값 찾기
            high--;
        }
        if (low <= high)
        {
            int temp = v[low];
            v[low] = v[high];
            v[high] = temp;
        }
    }
    int temp = v[l];
    v[l] = v[high];
    v[high] = temp;
    return high;
}

void QuickSort(int left, int right)
{
    if (left < right)
    {
        int q = partition(left, right);
        QuickSort(left, q - 1);
        QuickSort(q + 1, right);
    }
}

//1. sort 함수 사용
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        v.push_back(s[i]);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
}
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string a; // 문자열로 받을것!
    bool zero = false;
    vector<int> v;
    long long sum = 0;

    cin >> a;

    for (int i = 0; i < a.length(); i++)
    {
        int temp = a[i] - '0';
        if (temp == 0)
            zero = true;
        sum += temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end(), greater<int>());

    if (zero && sum % 3 == 0)
    {
        for (int num : v)
        {
            printf("%d", num);
        }
    }
    else
    {
        printf("-1");
    }
}
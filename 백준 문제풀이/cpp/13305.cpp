#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long n;
    long long price[100001];
    long long dis[100001];
    long long old;
    long long result;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> dis[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }

    result = dis[0] * price[0];
    old = price[0];

    for (int i = 1; i < n - 1; i++)
    {
        if (old > price[i])
            old = price[i];
        result += old * dis[i];
    }

    cout << result;
}
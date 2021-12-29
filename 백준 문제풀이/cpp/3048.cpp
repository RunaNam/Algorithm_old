#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;
int n1, n2, t;
string a, b, sum;
map<char, bool> m;

void jump()
{
    int i = 0;
    while (i < sum.size() - 1)
    {
        if (m[sum[i]] == false && m[sum[i + 1]] == true)
        {
            swap(sum[i], sum[i + 1]);
            i += 2;
        }
        else
        {
            i++;
        }
    }
}

int main()
{

    cin >> n1 >> n2;
    for (int i = 0; i < n1; i++)
    {
        char tmp;
        cin >> tmp;
        a += tmp;
        m[tmp] = false;
    }
    for (int i = 0; i < n2; i++)
    {
        char tmp;
        cin >> tmp;
        b += tmp;
        m[tmp] = true;
    }
    cin >> t;
    reverse(a.begin(), a.end());
    sum += a;
    sum += b;

    for (int i = 0; i < t; i++)
    {
        jump();
    }

    cout << sum;
    return 0;
}
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    vector<int> v;
    vector<int> answer;
    int sum = 0;
    bool ok = false;

    for (int i = 0; i < 9; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        v.push_back(tmp);
        sum += tmp;
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            int t = v[i] + v[j];
            int num1 = v[i];
            int num2 = v[j];
            if (sum - t == 100)
            {
                v.erase(find(v.begin(), v.end(), num1));
                v.erase(find(v.begin(), v.end(), num2));
                ok = true;
            }
            if (ok)
                break;
        }
        if (ok)
            break;
    }

    sort(v.begin(), v.end());

    for (int i : v)
    {
        printf("%d\n", i);
    }
}
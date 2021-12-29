#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> v;
    vector<int> d(16, 0);

    for (int i = 0; i < n; i++)
    {
        int t, p;
        scanf("%d %d", &t, &p);
        v.push_back({t, p});
    }

    for (int i = 0; i < n; i++)
    {
        int init = 0;
        if (i + v[i].first <= n)
        {
            init = v[i].second;
        }

        int tmp = init;
        for (int j = i - 1; j > -1; j--)
        {
            if (j + v[j].first <= i)
            {
                tmp = max(tmp, d[j] + init);
            }
        }
        d[i] = tmp;
    }

    printf("%d", *max_element(d.begin(), d.end()));
}
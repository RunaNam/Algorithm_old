#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int e = -1;

int main()
{
    int num;
    int result = 0;
    scanf("%d", &num);
    vector<pair<int, int>> v(num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d %d", &v[i].second, &v[i].first);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < num; i++)
    {
        if (e <= v[i].second)
        {
            e = v[i].first;
            result++;
        }
    }
    printf("%d", result);
}
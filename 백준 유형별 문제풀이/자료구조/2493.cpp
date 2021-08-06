#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        while (!v.empty())
        {
            if (t < v.back().second)
            {
                printf("%d ", v.back().first + 1);
                v.push_back({i, t});
                break;
            }
            else
            {
                v.pop_back();
            }
        }
        if (v.empty())
        {
            printf("0 ");
            v.push_back({i, t});
        }
    }

    return 0;
}
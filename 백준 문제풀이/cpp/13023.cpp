#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[2000];
bool f[2000] = {
    false,
};
int n, m;

void dfs(int x, int cnt)
{
    f[x] = true;
    if (cnt == 5)
    {
        printf("1");
        exit(0);
    }

    for (int i = 0; i < v[x].size(); i++)
    {
        if (!f[v[x][i]])
        {
            dfs(v[x][i], cnt + 1);
        }
    }

    f[x] = false;
}

int main()
{
    scanf("%d %d", &n, &m);
    int x, y;

    while (m--)
    {
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        dfs(i, 1);
    }

    printf("0");
    return 0;
}
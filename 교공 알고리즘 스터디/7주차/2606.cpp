#include <cstdio>
#include <vector>

using namespace std;

vector<int> v[101];
bool virus[101];
int cnt = 0;

void dfs(int a)
{
    virus[a] = true;

    for (int i = 0; i < v[a].size(); i++)
    {
        if (!virus[v[a][i]])
        {
            dfs(v[a][i]);
        }
    }
    cnt++;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    while (m--)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);

    printf("%d", cnt - 1);

    return 0;
}
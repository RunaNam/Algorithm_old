#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, v;
vector<int> vec[1001];
bool dcheck[1001] = {
    false,
};
bool bcheck[1001] = {
    false,
};

void bfs()
{
    queue<int> q;
    q.push(v);
    while (!q.empty())
    {
        int tmp = q.front();
        bcheck[tmp] = true;
        printf("%d ", tmp);
        q.pop();
        for (int i = 0; i < vec[tmp].size(); i++)
        {
            if (!bcheck[vec[tmp][i]])
            {
                q.push(vec[tmp][i]);
                bcheck[vec[tmp][i]] = true;
            }
        }
    }
}

void dfs(int a)
{
    dcheck[a] = true;
    printf("%d ", a);
    for (int i = 0; i < vec[a].size(); i++)
    {
        if (!dcheck[vec[a][i]])
            dfs(vec[a][i]);
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &v);
    for (int i = 0; i < m; i++)
    {
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        vec[t1].push_back(t2);
        vec[t2].push_back(t1);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(vec[i].begin(), vec[i].end());
    }
    dfs(v);
    printf("\n");
    bfs();

    return 0;
}

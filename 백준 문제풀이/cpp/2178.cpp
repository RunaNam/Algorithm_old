#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;
int a[100][100];
int ans[100][100];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m;

void bfs()
{
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    int count = 0;
    ans[0][0] = 1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int nc = ans[x][y];

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if (ans[nx][ny] == 0 && a[nx][ny] == 1)
                {
                    q.push(make_pair(nx, ny));
                    ans[nx][ny] = nc + 1;
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &a[i][j]);
        }
    }
    bfs();
    printf("%d", ans[n - 1][m - 1]);
}
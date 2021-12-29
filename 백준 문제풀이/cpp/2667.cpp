#pragma warning(disable : 4996)

#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;
int arr[25][25];
int visit[25][25] = {
    0,
};
int ans[25 * 25] = {
    0,
};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n;

void bfs(int x, int y, int num)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visit[x][y] = num;

    while (!q.empty())
    {
        pair<int, int> now = q.front();
        int xpos = now.first;
        int ypos = now.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            xpos += dx[i];
            ypos += dy[i];
            if (0 <= xpos && xpos < n && 0 <= ypos && ypos < n)
            {
                if (arr[xpos][ypos] == 1 && visit[xpos][ypos] == 0)
                {
                    q.push(make_pair(xpos, ypos));
                    visit[xpos][ypos] = num;
                }
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%1d", &arr[i][j]);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1 && visit[i][j] == 0)
            {
                bfs(i, j, ++cnt);
            }
        }
    }

    printf("%d\n", cnt);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[visit[i][j]] += 1;
        }
    }
    sort(ans + 1, ans + cnt + 1);
    for (int i = 1; i <= cnt; i++)
    {
        printf("%d\n", ans[i]);
    }
}
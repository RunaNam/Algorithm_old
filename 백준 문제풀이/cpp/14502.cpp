#include <queue>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int lab[8][8];
int tmp[8][8];
int result = 0;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs()
{
    int after_virus[8][8];
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            after_virus[i][j] = tmp[i][j];
            if (after_virus[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < m && 0 <= ny && ny < n)
            {
                if (after_virus[ny][nx] == 0)
                {
                    after_virus[ny][nx] = 2;
                    q.push({ny, nx});
                }
            }
        }
    }

    int empty = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (after_virus[i][j] == 0)
                empty++;
        }
    }
    result = max(result, empty);
}

void copy_lab(int lab[][8])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tmp[i][j] = lab[i][j];
        }
    }
}

void make_wall(int cnt)
{
    if (cnt == 3)
    {
        bfs();
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tmp[i][j] == 0)
            {
                tmp[i][j] = 1;
                make_wall(cnt + 1);
                tmp[i][j] = 0;
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
            scanf("%d", &lab[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (lab[i][j] == 0)
            {
                copy_lab(lab);
                tmp[i][j] = 1;
                make_wall(1);
                tmp[i][j] = 0;
            }
        }
    }

    printf("%d", result);
}
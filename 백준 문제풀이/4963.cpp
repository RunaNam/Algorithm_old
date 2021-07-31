#include <cstdio>
#include <vector>
using namespace std;

int w, h;
vector<int> v[50];
bool check[50][50] = {false};

int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

void dfs(int x, int y)
{
    check[x][y] = true;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < h && 0 <= ny && ny < w)
        {
            if (v[nx][ny] == 1 && !check[nx][ny])
                dfs(nx, ny);
        }
    }
}

int main()
{

    scanf("%d %d", &w, &h);

    while (w != 0 && h != 0)
    {
        int cnt = 0;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                int t;
                scanf("%d", &t);
                v[i].push_back(t);
            }
        }

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (v[i][j] == 1 && !check[i][j])
                {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);

        for (int i = 0; i < h; i++)
        {
            v[i].clear();
            for (int j = 0; j < w; j++)
            {
                check[i][j] = false;
            }
        }
        scanf("%d %d", &w, &h);
    }

    return 0;
}

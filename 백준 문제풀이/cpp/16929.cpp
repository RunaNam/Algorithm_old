#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 50

int n, m, sx, sy;
char v[MAX][MAX];
bool check[MAX][MAX];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool ans = false;

void dfs(int x, int y, int cnt)
{
    char c = v[x][y];
    check[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (cnt != 1 && nx == sx && ny == sy)
        {
            cout << "Yes";
            exit(0);
        }

        if (0 <= nx && nx <= MAX && 0 <= ny && ny <= MAX)
        {
            if (v[nx][ny] == c && !check[nx][ny])
            {
                dfs(nx, ny, cnt + 1);
            }
        }
    }
    check[x][y] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sx = i;
            sy = j;
            dfs(i, j, 0);
        }
    }
    cout << "No";
    return 0;
}
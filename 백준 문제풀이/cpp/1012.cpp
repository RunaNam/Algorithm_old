#include <cstdio>
#include <vector>
using namespace std;

int ground[50][50] = {
    0,
};
vector<pair<int, int>> cab;
bool check[50][50] = {
    false,
};

int cnt;
int t, m, n, k;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y)
{
    check[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < m && 0 <= ny && ny < n)
        {
            if (check[nx][ny] == false && ground[nx][ny] == 1)
            {
                cnt--;
                dfs(nx, ny);
            }
        }
    }
}

int main()
{
    int t1, t2;

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d %d", &m, &n, &k);
        cnt = k;
        for (int i = 0; i < k; i++)
        {
            scanf("%d %d", &t1, &t2);
            cab.push_back(make_pair(t1, t2));
            ground[t1][t2] = 1;
        }
        while (!cab.empty())
        {
            int x = cab.back().first;
            int y = cab.back().second;
            cab.pop_back();
            dfs(x, y);
        }

        for (int i = 0; i < m; i++)
        {
            for (int q = 0; q < n; q++)
            {
                ground[i][q] = 0;
                check[i][q] = false;
            }
        }
        printf("%d\n", cnt);
    }
}

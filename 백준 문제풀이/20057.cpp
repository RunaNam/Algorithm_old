#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int result = 0;

double blow[] = {0.05, 0.1, 0.1, 0.07, 0.07, 0.02, 0.02, 0.01, 0.01};
//int blow[] = { 5, 10, 10, 7, 7, 2, 2, 1, 1 };

int blowX[4][9] = {
    {-2, -1, -1, 0, 0, 0, 0, 1, 1},
    {0, 1, -1, -1, 1, -2, 2, -1, 1},
    {2, 1, 1, 0, 0, 0, 0, -1, -1},
    {0, 1, -1, -1, 1, -2, 2, -1, 1},
};
int blowY[4][9] = {
    {0, 1, -1, -1, 1, -2, 2, -1, 1},
    {2, 1, 1, 0, 0, 0, 0, -1, -1},
    {0, 1, -1, -1, 1, -2, 2, -1, 1},
    {-2, -1, -1, 0, 0, 0, 0, 1, 1},

};

void wind(int n, int xpos, int ypos, int dir, vector<vector<int>> &sand)
{
    int sandNow = sand[ypos][xpos];
    int leftSand = sandNow;

    int nx, ny;
    sand[ypos][xpos] = 0;

    for (int i = 0; i < 9; i++)
    {
        nx = xpos + blowX[dir][i];
        ny = ypos + blowY[dir][i];

        if (0 <= nx && nx < n && 0 <= ny && ny < n)
        {
            sand[ny][nx] += floor(blow[i] * sandNow);
        }
        else
        {
            result += floor(blow[i] * sandNow);
        }

        leftSand -= floor(blow[i] * sandNow);
    }

    nx = xpos + dx[dir];
    ny = ypos + dy[dir];
    if (0 <= nx && nx < n && 0 <= ny && ny < n)
    {
        sand[ny][nx] += leftSand;
    }
    else
    {
        result += leftSand;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<vector<int>> sand(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &sand[i][j]);
        }
    }
    int x = n / 2;
    int y = n / 2;
    int dir = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            x += dx[dir];
            wind(n, x, y, dir, sand);
        }
        dir++;
        for (int j = 1; j <= i; j++)
        {
            y += dy[dir];

            wind(n, x, y, dir, sand);
        }
        dir++;
        if (dir == 4)
            dir = 0;
    }

    for (int j = 1; j < n; j++)
    {
        x += dx[0];

        wind(n, x, y, 0, sand);
    }

    printf("%d", result);
}
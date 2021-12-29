#pragma warning(disable : 4996)
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

// ←, ↖, ↑, ↗, →, ↘, ↓, ↙
int fishX[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int fishY[] = {0, 1, 1, 1, 0, -1, -1, -1};

// 좌상우하
int sharkX[] = {-1, 0, 1, 0};
int sharkY[] = {0, -1, 0, 1};

void fishMove(vector<vector<int>> &field, int m)
{
}

int main()
{
    int m, s;
    scanf("%d %d", &m, &s);
    int x, y, p;

    // -1: 없음 -2: 물고기 냄새 0~7 : 물고기 있음(방향) 8: 상어
    vector<vector<int>> field(4, vector<int>(4, -1));

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &x, &y, &p);
        field[x - 1][y - 1] = p;
    }
    scanf("%d %d", &x, &y);
    field[x - 1][y - 1] = 8;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", field[i][j]);
        }
        printf("\n");
    }
}
#pragma warning(disable : 4996)
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int dx[8] = {-1, -1, 0, +1, +1, +1, 0, -1};
const int dy[8] = {0, -1, -1, -1, 0, +1, +1, +1};

struct Fish
{
    int x;
    int y;
    int dir;
    int fish_number;
    bool live = true;
};

int result = 0;

void move(vector<vector<int>> &v, Fish *fish, int shark_x, int shark_y, int sum)
{
    vector<vector<int>> cp_v(4, vector<int>(4));
    Fish cp_fish[16];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cp_v[i][j] = v[i][j];
        }
    }

    for (int i = 0; i < 16; i++)
    {
        cp_fish[i] = fish[i];
    }

    //상어가 먹음
    int n = cp_v[shark_x][shark_y];
    cp_v[shark_x][shark_y] = -1;

    //상어 이동방향 설정 + 물고기 죽음
    int shark_dir = cp_fish[n].dir;
    cp_fish[n].live = false;
    sum += cp_fish[n].fish_number;
    if (result < sum)
        result = sum;

    // 물고기 이동
    for (int i = 0; i < 16; i++)
    {
        if (cp_fish[i].live)
        {
            int x = cp_fish[i].x;
            int y = cp_fish[i].y;
            int dir = cp_fish[i].dir;

            int nx = x + (dx[dir % 8]);
            int ny = y + (dy[dir % 8]);

            while (nx < 0 || nx > 3 || ny < 0 || ny > 3 || (shark_x == nx && shark_y == ny))
            {
                dir++;
                nx = x + (dx[dir % 8]);
                ny = y + (dy[dir % 8]);
            }

            // 물고기 swap
            if (cp_v[nx][ny] != -1)
            {
                int swap_fish = cp_v[nx][ny];
                cp_fish[i].x = nx;
                cp_fish[i].y = ny;
                cp_fish[i].dir = dir;
                cp_fish[swap_fish].x = x;
                cp_fish[swap_fish].y = y;

                cp_v[nx][ny] = i;
                cp_v[x][y] = swap_fish;
            }
            else
            {
                cp_fish[i].x = nx;
                cp_fish[i].y = ny;
                cp_fish[i].dir = dir;
                cp_v[nx][ny] = i;
                cp_v[x][y] = -1;
            }
        }
    }

    //상어 이동
    for (int i = 1; i < 4; i++)
    {
        int dir_x = dx[shark_dir % 8] * i;
        int dir_y = dy[shark_dir % 8] * i;
        int nx = shark_x + dir_x;
        int ny = shark_y + dir_y;

        if (nx < 0 || nx > 3 || ny < 0 || ny > 3)
            break;

        if (cp_v[nx][ny] != -1)
        {
            move(cp_v, cp_fish, nx, ny, sum);
        }
    }
}

int main()
{
    vector<vector<int>> v(4, vector<int>(4));
    Fish fish[16];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int n, d;
            scanf("%d %d", &n, &d);
            n--;
            d--;
            v[i][j] = n;
            fish[n].x = i;
            fish[n].y = j;
            fish[n].dir = d;
            fish[n].fish_number = n + 1;
        }
    }

    move(v, fish, 0, 0, 0);
    printf("%d", result);
    return 0;
}
#include <cstdio>
#include <queue>
#include <iostream>
#include <utility>
using namespace std;
#define MY_MAX 1001

int row, col;
int mycount = 0;
int tomato[MY_MAX][MY_MAX] = {
    0,
};
int map[MY_MAX][MY_MAX] = {
    0,
};

queue<pair<int, int>> q;

int Tomato()
{
    int first, second;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        first = p.first;
        second = p.second;
        q.pop();
        if (first - 1 > -1 && !tomato[first - 1][second] && map[first - 1][second] == 0)
        {
            tomato[first - 1][second] = tomato[first][second] + 1;
            q.push(make_pair(first - 1, second));
        }

        if (second - 1 > -1 && !tomato[first][second - 1] && map[first][second - 1] == 0)
        {
            tomato[first][second - 1] = tomato[first][second] + 1;
            q.push(make_pair(first, second - 1));
        }
        if (first + 1 < row && !tomato[first + 1][second] && map[first + 1][second] == 0)
        {
            tomato[first + 1][second] = tomato[first][second] + 1;
            q.push(make_pair(first + 1, second));
        }

        if (second + 1 < col && !tomato[first][second + 1] && map[first][second + 1] == 0)
        {
            tomato[first][second + 1] = tomato[first][second] + 1;
            q.push(make_pair(first, second + 1));
        }
    }
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (tomato[j][i] == 0 && map[j][i] == 0)
            {
                return -1;
            }
        }
    }
    return tomato[first][second] - 1;
}
int main()
{
    scanf("%d %d", &row, &col);
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[j][i] == 1)
            {
                q.push(make_pair(j, i));
                tomato[j][i] = 1;
            }
        }
    }

    printf("%d", Tomato());
    return 0;
}
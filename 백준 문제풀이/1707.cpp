#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> board;
vector<int> check;

int cnt;
int t, v, e;
bool result = true;

void dfs(int a, int color)
{
    check[a] = color;
    for (int i = 0; i < board[a].size(); i++)
    {
        if (check[board[a][i]] == 0)
        {
            dfs(board[a][i], 3 - color);
        }
    }
}

bool ans_check()
{
    for (int i = 0; i < check.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (check[i] == check[board[i][j]])
                return false;
        }
    }
    return true;
}

int main()
{
    int t1, t2;

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &v, &e);
        board.assign(v + 1, vector<int>(0, 0));
        check.assign(v + 1, 0);

        while (e--)
        {
            scanf("%d %d", &t1, &t2);
            board[t1].push_back(t2);
            board[t2].push_back(t1);
        }

        for (int i = 1; i <= v; i++)
        {
            if (check[i] == 0)
                dfs(i, 1);
        }

        if (ans_check())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

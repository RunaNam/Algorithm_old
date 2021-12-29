#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

//  n의 절반크기만큼 두 그룹을 만들고 > 순열 사용해서 반반씩 나눠서 그걸로 해도 될듯.
//  두 그룹의 능력치 차이를 계산해서
//  최소값 구해야됨.

int calculate_level(vector<int> team, vector<vector<int>> combination)
{
    int result = 0;
    do
    {
        result += combination[team[0]][team[1]] + combination[team[1]][team[0]];
    } while (next_permutation(team.begin(), team.end()));
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<vector<int>> combination(n, vector<int>(n, 0));
    vector<int> player;
    vector<int> check;
    int diff_min = 1000000;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &combination[i][j]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        player.push_back(i - 1);
        if (i < n / 2)
            check.push_back(1);
        else
            check.push_back(0);
    }

    do
    {
        vector<int> team1;
        vector<int> team2;
        for (int i = 0; i < n; i++)
        {
            if (check[i] == 1)
            {
                team1.push_back(player[i]);
            }
            else
            {
                team2.push_back(player[i]);
            }
        }
        int tmp = abs(calculate_level(team1) - calculate_level(team2));
        diff_min = min(tmp, diff_min);

    } while (next_permutation(player.begin(), player.end()));

    printf("%d", &diff_min);
}
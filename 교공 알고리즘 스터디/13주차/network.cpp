#include <string>
#include <vector>

using namespace std;
vector<bool> check;
int answer;

void dfs(int n, vector<vector<int>> computers, int num)
{
    check[num] = true;
    for (int i = 0; i < n; i++)
    {
        if (i != num && computers[num][i] != 0 && check[i] == false)
        {
            answer--;
            dfs(n, computers, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{
    check.assign(n, false);
    answer = n;

    for (int i = 0; i < n; i++)
    {
        dfs(n, computers, i);
    }

    return answer;
}
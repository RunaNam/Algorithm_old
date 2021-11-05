#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool visit[100001] = {
    false,
};
vector<string> answer;

bool cmp(vector<string> &a, vector<string> b)
{
    if (a.at(0) == b.at(0))
    {
        return a.at(1) > b.at(1);
    }
    return a.at(0) > b.at(0);
}

void dfs(vector<vector<string>> tickets, string now, int cnt, vector<string> tmp)
{
    tmp.push_back(now);
    if (cnt == tickets.size())
    {
        answer = tmp;
        return;
    }
    for (int i = 0; i < tickets.size(); i++)
    {
        if (now == tickets[i][0] && visit[i] == false)
        {
            visit[i] = true;
            dfs(tickets, tickets[i][1], cnt + 1, tmp);
            visit[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    sort(tickets.begin(), tickets.end(), cmp);

    dfs(tickets, "ICN", 0, answer);

    return answer;
}
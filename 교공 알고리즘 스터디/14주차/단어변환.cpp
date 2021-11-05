#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer = 100;
bool visit[51] = {
    false,
};

void dfs(string now, string target, vector<string> words, int cnt)
{
    vector<pair<int, string>> tmp;
    if (now == target)
    {
        if (answer > cnt)
            answer = cnt;
        return;
    }

    for (int i = 0; i < words.size(); i++)
    {
        int tmp_cnt = 0;
        for (int j = 0; j < now.size(); j++)
        {
            if (now[j] != words[i][j])
                tmp_cnt++;
        }
        if (tmp_cnt == 1)
        {
            tmp.push_back({i, words[i]});
        }
    }

    for (auto a : tmp)
    {
        if (visit[a.first] == false)
        {
            visit[a.first] = true;
            dfs(a.second, target, words, cnt + 1);
            visit[a.first] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words)
{
    dfs(begin, target, words, 0);
    if (answer == 100)
        return 0;

    return answer;
}
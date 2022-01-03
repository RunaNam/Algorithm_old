#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> answer(2, 0);
    priority_queue<int, vector<int>, greater<int>> min;
    priority_queue<int, vector<int>, less<int>> max;
    int cnt = 0;

    for (int i = 0; i < operations.size(); i++)
    {

        if (operations[i][0] == 'I')
        {
            int tmp = stoi(operations[i].substr(1));
            min.push(tmp);
            max.push(tmp);
            cnt++;
        }
        else if (operations[i][0] == 'D')
        {
            if (cnt == 0)
                continue;
            if (operations[i][2] == '-')
            {
                min.pop();
                cnt--;
            }
            else
            {
                max.pop();
                cnt--;
            }
        }

        if (cnt == 0)
        {
            while (!min.empty())
                min.pop();
            while (!max.empty())
                max.pop();
        }
    }

    if (cnt <= 0)
    {
        return answer;
    }

    answer[0] = max.top();
    answer[1] = min.top();

    return answer;
}

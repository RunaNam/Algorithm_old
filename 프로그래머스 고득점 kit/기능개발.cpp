#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    deque<int> counts;
    vector<int> result;
    int tmp;
    int cnt;

    for (int i = 0; i < progresses.size(); i++)
    {
        tmp = progresses[i];
        cnt = 0;
        while (tmp < 100)
        {
            tmp += speeds[i];
            cnt++;
        }
        counts.push_back(cnt);
    }

    while (!counts.empty())
    {
        tmp = counts.front();
        cnt = 1;
        counts.pop_front();
        while (!counts.empty() && tmp >= counts.front())
        {
            counts.pop_front();
            cnt++;
        }
        result.push_back(cnt);
    }

    return result;
}

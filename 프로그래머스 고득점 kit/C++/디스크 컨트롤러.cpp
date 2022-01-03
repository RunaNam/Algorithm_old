#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

struct cmp
{
    bool operator()(vector<int> a, vector<int> b)
    {
        return a.at(1) > b.at(1);
    }
};

int solution(vector<vector<int>> jobs)
{
    int result = 0;
    int j = 0;    // 인덱스 관리용
    int time = 0; // 시간 체크

    sort(jobs.begin(), jobs.end(), compare);

    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

    while (j < jobs.size() || !pq.empty())
    {
        if (jobs.size() > j && time >= jobs[j][0])
        {
            pq.push(jobs[j++]);
            continue;
        }
        if (!pq.empty())
        {
            time += pq.top()[1];
            result += time - pq.top()[0];
            pq.pop();
        }
        else
        {
            time = jobs[j][0];
        }
    }
    return result / jobs.size();
}
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// min_element 사용한버전 (힙인거 생각 안하고 품)
// 정확성은 다 맞는데 효율성에서 다 틀림.
int solution(vector<int> scoville, int K)
{
    int result = 0;
    while (*min_element(scoville.begin(), scoville.end()) < K)
    {
        if (scoville.size() < 2)
        {
            return -1;
        }

        auto i = min_element(scoville.begin(), scoville.end());
        int tmp = *i;
        scoville.erase(i);

        auto i2 = min_element(scoville.begin(), scoville.end());
        tmp += (*i2) * 2;
        scoville.erase(i2);
        scoville.push_back(tmp);

        result++;
    }
    if (result != 0)
        return result;
    else
        return -1;
}

// 제대로 prioroty queue 쓴거. (힙 사용)
int solution(vector<int> scoville, int K)
{
    int result = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    while (pq.size() > 1 && pq.top() < K)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        pq.push(first + (second * 2));
        result++;
    }
    if (pq.top() < K)
        return -1;
    return result;
}

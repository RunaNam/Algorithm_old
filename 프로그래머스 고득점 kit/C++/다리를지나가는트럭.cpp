#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    queue<int> q;
    int answer = 0;
    int bridgeWeight = 0;
    int idx = 0;

    while (1)
    {
        answer++;

        if (q.size() == bridge_length)
        {
            bridgeWeight -= q.front();
            q.pop();
        }
        if (bridgeWeight + truck_weights[idx] <= weight)
        {
            if (idx == truck_weights.size() - 1)
            {
                answer += bridge_length;
                break;
            }
            q.push(truck_weights[idx]);
            bridgeWeight += truck_weights[idx];
            idx++;
        }
        else
        {
            q.push(0);
        }
    }
}

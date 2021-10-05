#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int answer = 0;

int main(void)
{
    int n, length, weight, t;
    cin >> n >> length >> weight;
    int answer = 0;
    queue<int> waiting_trucks;
    queue<pair<int, int>> moving_trucks;
    vector<int> arrived_trucks;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        waiting_trucks.push(t);
    }

    while (arrived_trucks.size() < n)
    {
        answer++;
        int front_truck = 0;

        if (moving_trucks.size() > 0)
        {
            if (moving_trucks.front().second == answer)
            {
                int z = moving_trucks.front().first;
                arrived_trucks.push_back(z);
                sum -= z;
                moving_trucks.pop();
            }
        }
        if (waiting_trucks.size() > 0)
        {
            front_truck = waiting_trucks.front();
            if (sum + front_truck <= weight)
            {
                sum += front_truck;
                waiting_trucks.pop();
                moving_trucks.push(make_pair(front_truck, answer + length));
            }
        }
    }
    cout << answer;
}
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
vector<pair<int, int>> v;
bool canGo = false;

int dist(pair<int, int> p1, pair<int, int> p2)
{
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void bfs()
{
    queue<pair<int, int>> q;
    q.push(v[0]);
    int check[102] = {
        0,
    };

    canGo = false;

    while (!q.empty())
    {
        if (canGo)
            break;
        pair<int, int> now = q.front();
        q.pop();

        for (int i = 1; i < v.size() - 1; i++)
        {
            if (dist(now, v[i]) <= 1000 && check[i] == 0)
            {
                q.push(v[i]);
                check[i] = 1;
            }
            else if (dist(now, v[v.size() - 1]) <= 1000)
                canGo = true;
        }
    }
}

int main()
{
    int t, n;
    cin >> t;
    // 거리 집어넣음
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j < n + 2; j++)
        {
            int x, y;
            cin >> x >> y;
            v.push_back(make_pair(x, y));
        }
        bfs();
        if (canGo)
            cout << "happy" << '\n';
        else
            cout << "sad" << '\n';
    }
    return 0;
}
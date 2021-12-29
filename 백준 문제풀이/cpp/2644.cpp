#include <queue>
#include <iostream>

using namespace std;
int dist[101] = {0};
vector<int> v[101];

int bfs(int start, int end)
{
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        if (x == end)
            return dist[end];

        long long size = v[x].size();

        for (int i = 0; i < size; i++)
        {
            int y = v[x][i];

            if (!dist[y])
            {
                q.push(y);
                dist[y] = dist[x] + 1;
            }
        }
    }
    return -1;
}

int main()
{
    int n, a, b, m;
    cin >> n;
    cin >> a >> b;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }

    cout << bfs(a, b) << '\n';
    return 0;
}
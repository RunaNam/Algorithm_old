#include <cstdio>
#include <queue>
using namespace std;

int visited[100001] = {
    0,
};
int n, k;

int bfs()
{
    queue<int> q;
    q.push(n);
    visited[n] = 1;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        if (p == k)
            return visited[p] - 1;

        if (p - 1 >= 0 && visited[p - 1] == 0)
        {
            visited[p - 1] = visited[p] + 1;
            q.push(p - 1);
        }
        if (p + 1 <= 100000 && visited[p + 1] == 0)
        {
            visited[p + 1] = visited[p] + 1;
            q.push(p + 1);
        }
        if (p * 2 <= 100000 && visited[p * 2] == 0)
        {
            visited[p * 2] = visited[p] + 1;
            q.push(p * 2);
        }
    }
}

int main(void)
{
    scanf("%d %d", &n, &k);
    printf("%d", bfs());
}
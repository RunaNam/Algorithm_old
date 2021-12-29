#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n, m;
int num[1001][1001] = {
    0,
};
bool visited[1001];

void DFS(int a)
{
    visited[a] = true;
    for (int i = 0; i < n; i++)
    {
        if (num[a][i] == 1 && !visited[i])
            DFS(i);
    }
}

int main(void)
{
    int cnt = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        num[a][b] = 1;
        num[b][a] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cnt++;
            DFS(i);
        }
    }
}
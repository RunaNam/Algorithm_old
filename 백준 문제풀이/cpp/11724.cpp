#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> adj[1001];
int visited[1001];
int point, num;

void DFS(int a)
{
    visited[a] = 1;
    for (int i = 0; i < adj[a].size(); i++)
    {
        int next = adj[a][i];
        if (!visited[next])
            DFS(next);
    }
}

int main(void)
{
    scanf("%d %d", &point, &num);
    for (int i = 0; i < num; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cnt = 0;

    for (int i = 1; i <= point; i++)
    {
        if (!visited[i])
        {
            DFS(i);
            cnt++;
        }
    }

    printf("%d", cnt);
}
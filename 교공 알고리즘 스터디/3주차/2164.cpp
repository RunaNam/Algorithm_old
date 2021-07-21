#include <cstdio>
#include <queue>
using namespace std;

int n;

void check()
{
    queue<int> q;
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    while (q.size() != 1)
    {
        if (count % 2 == 1)
        {
            q.pop();
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
        count++;
    }
    printf("%d", q.front());
}

int main()
{
    scanf("%d", &n);
    check();
    return 0;
}

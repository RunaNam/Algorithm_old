#include <cstdio>
#include <queue>

using namespace std;

priority_queue<int> q;

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int t;
        scanf("%d", &t);
        if (t == 0)
        {
            if (q.empty())
            {
                printf("0\n");
            }
            else
            {
                printf("%d\n", q.top());
                q.pop();
            }
        }
        else
        {
            q.push(t);
        }
    }

    return 0;
}
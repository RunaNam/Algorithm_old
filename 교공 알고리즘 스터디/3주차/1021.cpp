#include <cstdio>
#include <deque>
using namespace std;

int n, m;
deque<int> dq;
int cnt = 0;

void check(int tmp)
{
    int l, r;
    for (int i = 1; i < dq.size(); i++)
    {
        if (dq[i] == tmp)
        {
            l = i;
            r = dq.size() - i;
            break;
        }
    }

    if (l < r)
    {
        for (int i = 0; i < l; i++)
        {
            dq.push_back(dq.front());
            dq.pop_front();
        }
        cnt += l;
    }
    else
    {
        for (int i = 0; i < r; i++)
        {
            dq.push_front(dq.back());
            dq.pop_back();
        }
        cnt += r;
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        dq.push_back(i);
    }
    while (m--)
    {
        int tmp;
        scanf("%d", &tmp);

        if (dq.front() != tmp)
        {
            check(tmp);
            dq.pop_front();
        }
        else
        {
            dq.pop_front();
        }
    }
    printf("%d", cnt);
    return 0;
}

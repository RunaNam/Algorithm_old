#include <iostream>
#include <deque>
using namespace std;

int t, n, m;
deque<int> dq;

int check()
{
    int pos = m;
    int result = 0;
    while (1)
    {
        int cnt = 0;

        int a;
        a = dq.front();
        dq.pop_front();

        if (dq.empty())
        {
            return result + 1;
        }

        if (pos == 0)
        {
            for (int i = 0; i < dq.size(); i++)
            {
                if (dq.at(i) > a)
                {
                    dq.push_back(a);
                    pos = dq.size() - 1;
                    break;
                }
                else
                {
                    cnt++;
                }

                if (cnt == dq.size())
                {
                    return result + 1;
                }
            }
        }
        else
        {
            for (int i = 0; i < dq.size(); i++)
            {
                if (dq.at(i) > a)
                {
                    dq.push_back(a);
                    pos--;
                    break;
                }
                else
                {
                    cnt++;
                }

                if (cnt == dq.size())
                {
                    result++;
                    pos--;
                }
            }
        }
    }
}

int main()
{
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            int tmp;
            scanf("%d", &tmp);

            dq.push_back(tmp);
        }

        printf("%d\n", check());

        dq.clear();
    }
}
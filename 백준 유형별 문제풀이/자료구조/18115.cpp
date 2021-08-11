#include <cstdio>
#include <deque>
#include <vector>

using namespace std;

deque<int> result;
vector<int> v;

int main()
{
    int n, t;
    scanf("%d", &n);
    v.assign(n, 0);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &v[n - i]);
    }

    for (int i = 1; i <= n; i++)
    {
        int a = v[i - 1];

        switch (a)
        {
        case 1:
            result.push_front(i);
            break;

        case 2:
            if (result.size() != 0)
            {
                t = result.front();
                result.pop_front();
                result.push_front(i);
                result.push_front(t);
            }
            else
            {
                result.push_front(i);
            }
            break;

        case 3:
            result.push_back(i);
            break;

        default:
            break;
        }
    }
    for (auto i = result.begin(); i != result.end(); i++)
    {
        printf("%d ", *i);
    }

    return 0;
}
#include <cstdio>
#include <vector>
#include <set>

using namespace std;
vector<int> v(12);
int n;
int p, mi, mu, d;
set<long long> s;

void check(int plus, int minus, int multiple, int divide, int pos, long long result)
{
    if (pos == n)
        s.insert(result);
    else
    {
        long long tmp;
        if (plus != 0)
        {
            tmp = result + v[pos];
            check(plus - 1, minus, multiple, divide, pos + 1, tmp);
        }
        if (minus != 0)
        {
            tmp = result - v[pos];
            check(plus, minus - 1, multiple, divide, pos + 1, tmp);
        }
        if (multiple != 0)
        {
            tmp = result * v[pos];
            check(plus, minus, multiple - 1, divide, pos + 1, tmp);
        }
        if (divide != 0)
        {
            tmp = result / v[pos];
            check(plus, minus, multiple, divide - 1, pos + 1, tmp);
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    scanf("%d %d %d %d", &p, &mi, &mu, &d);
    check(p, mi, mu, d, 1, v[0]);

    printf("%ld\n", *s.rbegin());
    printf("%ld", *s.begin());

    return 0;
}
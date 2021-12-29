#include <cstdio>
#include <vector>

using namespace std;

int a[1000000];

int main()
{
    int n;
    int b, c;
    long long count;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d %d", &b, &c);

    count = n;

    for (int i = 0; i < n; i++)
    {
        int tmp = a[i] - b;
        if (tmp > 0)
        {
            count += tmp / c;
            if (tmp % c != 0)
                count++;
        }
    }
    printf("%lld", count);
}
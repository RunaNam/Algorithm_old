#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[12] = {
    0,
};

int minv = 100000000;
int maxv = -100000000;

void DFS(int count, int p, int mi, int mu, int d, int sum)
{
    if (count == n)
    {

        maxv = max(sum, maxv);
        minv = min(sum, minv);
    }
    if (p > 0)
    {
        DFS(count + 1, p - 1, mi, mu, d, sum + a[count]);
    }
    if (mi > 0)
    {
        DFS(count + 1, p, mi - 1, mu, d, sum - a[count]);
    }
    if (mu > 0)
    {
        DFS(count + 1, p, mi, mu - 1, d, sum * a[count]);
    }
    if (d > 0)
    {
        DFS(count + 1, p, mi, mu, d - 1, sum / a[count]);
    }
}

int main()
{
    int p, mi, mu, d;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d %d %d %d", &p, &mi, &mu, &d);
    DFS(1, p, mi, mu, d, a[0]);

    printf("%d\n%d", maxv, minv);
}
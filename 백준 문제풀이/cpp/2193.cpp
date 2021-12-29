//2193 이친수

#include <stdio.h>
long long d[91][1];
int main(void)
{
    int a;
    scanf("%d", &a);

    d[1][1] = 1;
    d[1][0] = 0;

    for (int i = 2; i <= a; i++)
    {
        d[i][1] = d[i - 1][0];
        d[i][0] = d[i - 1][1] + d[i - 1][0];
    }

    printf("%lld", d[a][1] + d[a][0]);
}
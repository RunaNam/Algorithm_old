//15990 123더하기

#include <stdio.h>
long long d[1000001][4];
const long long MOD = 1000000009LL;
int main(void)
{
    d[1][1] = d[2][2] = 1;
    d[3][1] = d[3][2] = d[3][3] = 1;

    for (int i = 4; i <= 100000; i++)
    {
        d[i][1] = (d[i - 1][2] + d[i - 1][3]) % MOD;
        d[i][2] = (d[i - 2][3] + d[i - 2][1]) % MOD;
        d[i][3] = (d[i - 3][2] + d[i - 3][1]) % MOD;
    }

    int count;
    scanf("%d", &count);
    while (count--)
    {
        int a;
        scanf("%d", &a);
        printf("%lld\n", (d[a][1] + d[a][2] + d[a][3]) % MOD);
    }
}
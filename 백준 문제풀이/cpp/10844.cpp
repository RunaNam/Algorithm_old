//10844 쉬운 계단수
#include <stdio.h>
long long d[101][10];
#define MOD 1000000000

int main(void)
{
    int a;
    long long ans = 0;

    scanf("%d", &a);
    for (int i = 1; i < 10; i++)
        d[1][i] = 1;

    for (int i = 2; i <= a; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            d[i][j] = 0;
            if (j - 1 >= 0)
            {
                d[i][j] += d[i - 1][j - 1];
            }
            if (j + 1 <= 9)
            {
                d[i][j] += d[i - 1][j + 1];
            }
            d[i][j] %= MOD;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        ans += d[a][i];
    }
    printf("%d", ans % MOD);
}

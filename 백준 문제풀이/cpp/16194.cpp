//16194 카드 구매하기 2

#include <cstdio>
using namespace std;
int d[1001];
int f[1000];
int main(void)
{
    int count;
    int num;
    int i = 1;

    scanf("%d", &count);
    num = count;

    while (count--)
    {
        scanf("%d", &f[i++]);
    }

    d[1] = f[1];
    for (int i = 2; i <= num; i++)
    {
        int min = f[i];
        for (int j = 1; j <= i / 2; j++)
        {
            if (d[j] + d[i - j] < min)
                min = d[j] + d[i - j];
        }
        d[i] = min;
    }
    printf("%d", d[num]);
    return 0;
}
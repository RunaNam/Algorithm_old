#include <cstdio>
using namespace std;
int d[12];

int main(void)
{
    d[1] = 1;
    d[2] = 2;
    d[3] = 3;
    for (int i = 4; i < 11; i++)
    {
        d[i] = d[i - 1] + d[i - 2] + d[i - 3];
    }

    int count;
    scanf("%d", &count);
    while (count--)
    {
        int a;
        scanf("%d", &a);
        printf("%d", d[count]);
    }
    return 0;
}
#include <cstdio>
using namespace std;
int memo[41];

int main()
{
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 1;
    for (int i = 3; i < 41; i++)
    {
        memo[i] = memo[i - 1] + memo[i - 2];
    }
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        if (n == 0)
            printf("1 0 \n");
        else if (n == 1)
            printf("0 1 \n");

        else
            printf("%d %d\n", memo[n - 1], memo[n]);
    }
}
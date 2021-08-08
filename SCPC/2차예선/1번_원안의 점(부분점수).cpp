#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

long long int cnt = 0;
long long int R[200001] = {
    0,
};
int point[200001] = {
    0,
};
int r;

void check()
{
    for (int i = 2; i <= 1000; i++)
    {
        long long int tmp = 0;

        for (int x = 1; x < i; x++)
        {
            int y = point[x] + 1;
            for (y; y < i; y++)
            {
                if (pow(i, 2) > (pow(x, 2) + pow(y, 2)))
                {
                    tmp++;
                    point[x] = y;
                }
                else
                    break;
            }
        }

        R[i] = R[i - 1] + 4 + tmp * 4;
    }
}

int main()
{
    int t;
    R[1] = 1;

    scanf("%d", &t);
    check();

    for (int i = 0; i < t; i++)
    {
        cnt = 0;
        scanf("%d", &r);

        printf("Case #%d\n", i + 1);
        printf("%ld\n", R[r]);
    }

    return 0;
}
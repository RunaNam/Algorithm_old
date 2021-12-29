#include <cstdio>

using namespace std;
int nums[1001];
int d[1001];

int main(void)
{
    d[0] = 1;
    int num;
    int biggest = 0;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &nums[i]);
    }

    for (int i = 0; i < num; i++)
    {
        d[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i] && d[i] < d[j] + 1)
            {
                d[i] = d[j] + 1;
            }
        }

        if (biggest < d[i])
            biggest = d[i];
    }
    printf("%d", biggest);
}
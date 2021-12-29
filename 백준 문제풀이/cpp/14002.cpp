#include <cstdio>

using namespace std;
int nums[1001];
int d[1001];
int prev[1001];
int result[1001];

int main(void)
{
    int num;
    int biggest = 0;
    int idx = 0;

    int count = 0;
    int p;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &nums[i]);
    }

    for (int i = 0; i < num; i++)
    {
        d[i] = 1;
        prev[i] = i;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i] && d[i] < d[j] + 1)
            {
                d[i] = d[j] + 1;
                prev[i] = j;
            }
        }

        if (biggest < d[i])
        {
            idx = i;
            biggest = d[i];
        }
    }

    printf("%d\n", biggest);

    for (p = idx; p != prev[p]; p = prev[p])
        result[count++] = nums[p];
    result[count] = nums[p];

    for (int i = count; i > -1; i--)
    {
        printf("%d ", result[i]);
    }
}
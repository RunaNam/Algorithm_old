#include <cstdio>
using namespace std;

int d[100001];
int nums[100001];

int main(void)
{
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &nums[i]);
    }

    int biggest = nums[0];
    for (int i = 0; i < num; i++)
    {
        d[i] = nums[i];
        if (d[i - 1] + nums[i] > nums[i])
            d[i] = d[i - 1] + nums[i];
        if (biggest < d[i])
            biggest = d[i];
    }
    printf("%d", biggest);
}
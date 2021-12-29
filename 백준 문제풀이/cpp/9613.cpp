#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main(void)
{
    int count;
    scanf("%d", &count);
    while (count--)
    {
        int nums[111];
        int num;
        long result = 0;
        scanf("%d", &num);
        for (int i = 0; i < num; i++)
        {
            scanf("%d", &nums[i]);
        }
        for (int j = 0; j < num - 1; j++)
        {
            for (int z = j + 1; z < num; z++)
            {
                result += gcd(nums[j], nums[z]);
            }
        }
        printf("%d\n", result);
    }
    return 0;
}
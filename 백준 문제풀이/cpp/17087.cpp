#include <iostream>
#include <cstdio>
using namespace std;
int nums[100000];

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

int main(void)
{
    int a, b;
    int gcd = 0;
    scanf("%d %d", &a, &b);

    for (int i = 0; i < a; i++)
    {
        scanf("%d", &nums[i]);
    }

    gcd = nums[0] - b;
    if (gcd < 0)
        gcd = -gcd;

    for (int i = 1; i < a; i++)
    {
        if (nums[i] > b)
            gcd = GCD(gcd, nums[i] - b);
        else
            gcd = GCD(gcd, b - nums[i]);
    }

    printf("%d", gcd);
    return 0;
}
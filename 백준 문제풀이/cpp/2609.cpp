#include <iostream>
#include <cstdio>
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
    int a, b;
    int Gcd, Lcm;
    scanf("%d %d", &a, &b);
    Gcd = gcd(a, b);
    Lcm = Gcd * (a / Gcd) * (b / Gcd);
    printf("%d\n%d", Gcd, Lcm);
}
#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
    int a, b, c;
    int tmp1, tmp2, tmp3, tmp4;
    scanf("%d %d %d", &a, &b, &c);
    tmp1 = a + b;
    tmp2 = a % c;
    tmp3 = b % c;
    tmp4 = a * b;
    printf("%d\n%d\n%d\n%d\n", tmp1 % c, (tmp2 + tmp3) % c, tmp4 % c, (tmp2 * tmp3) % c);
    return 0;
}
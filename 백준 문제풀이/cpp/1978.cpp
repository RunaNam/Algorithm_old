#include <iostream>
#include <cstdio>
using namespace std;

bool prime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main(void)
{
    int count;
    int result = 0;
    int num[100];
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &num[i]);
        if (prime(num[i]))
            result++;
    }
    printf("%d", result);
    return 0;
}
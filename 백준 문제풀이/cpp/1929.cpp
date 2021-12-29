#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
    int pn = 0;
    bool check[1000000];
    check[0] = check[1] = true;
    for (int i = 2; i * i < 1000000; i++)
    {
        if (check[i] == false)
        {
            for (int j = i + i; j <= 1000000; j += i)
                check[j] = true;
        }
    }
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++)
    {
        if (check[i] == false)
            printf("%d\n", i);
    }
    return 0;
}
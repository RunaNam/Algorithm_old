#include <iostream>
#include <cstdio>
using namespace std;
int pn = 0;
bool check[1000001];
int prime[1000000];
int main(void)
{

    check[0] = check[1] = true;
    for (int i = 2; i * i < 1000000; i++)
    {
        if (check[i] == false)
        {
            prime[pn++] = i;
            for (int j = i * 2; j <= 1000000; j += i)
                check[j] = true;
        }
    }

    while (true)
    {
        int a = 0;
        scanf("%d", &a);
        if (a == 0)
            break;
        for (int j = 1; j < pn; j++)
        {
            if (!check[a - prime[j]])
            {
                printf("%d = %d + %d\n", a, prime[j], a - prime[j]);
                break;
            }
        }
    }
    return 0;
}
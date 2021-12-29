#include <iostream>
#include <cstdio>

#define MAX 1000000
using namespace std;

bool check[MAX + 1];
int prime[MAX];
int pn = 0;

int main(void)
{
    check[0] = check[1] = true;
    for (int i = 2; i < MAX; i++)
    {
        if (check[i] == false)
        {
            prime[pn++] = i;
            for (int j = i * 2; j < MAX; j += i)
                check[j] = true;
        }
    }

    int num;
    scanf("%d", &num);

    while (num--)
    {
        int a;
        int result = 0;

        scanf("%d", &a);

        for (int i = 0; prime[i] * 2 <= a; i++)
        {
            if ((check[a - prime[i]]) == false)
            {
                result++;
            }
        }

        printf("%d\n", result);
    }
    return 0;
}
#include <iostream>
using namespace std;

int n;
int prime[1004000];
bool check[1004001];

void primeCheck()
{
    for (int i = 2; i * i < 1004000; i++)
    {
        int pn = 0;
        if (check[i] == false)
        {
            prime[pn++] = i;
            for (int j = i + i; j < 1004000; j += i)
            {
                check[j] = false;
            }
        }
    }
}

int main(void)
{
    int pn = 0;
    int result;
    scanf("%d", &n);
    primeCheck();

    for (int i = 0; i < 1004000; i++)
    {
        if (n < prime[i])
        {
            pn = i;
            break;
        }
    }
    for (int i = pn; i < 1004000; i++)
    {
        int num = prime[i];
        if (10 < num && num < 100)
        {
            if (num / 10 == num % 10)
            {
                result = num;
                break;
            }
        }
        else if (num < 1000)
        {
            if (num / 100 == num % 10)
            {
                result = num;
                break;
            }
        }
        else if (num < 10000)
        {
            if (num % 100 == num / 100)
            {
                result = num;
                break;
            }
        }
        else if (num < 100000)
        {
            if (num % 1000 == num / 100)
            {
                result = num;
                break;
            }
        }
        else
        {
            if (num % 1000 == num / 1000)
            {
                result = num;
                break;
            }
        }
    }
    printf("%d", result);
}

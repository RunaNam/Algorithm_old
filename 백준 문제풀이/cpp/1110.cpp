#include <iostream>
using namespace std;

int main()
{
    int n;
    int newN;
    int count = 1;
    scanf("%d", &n);
    if (n == 0)
    {
        printf("1");
        return 0;
    }
    else if (n < 10)
        newN = n + 10 * n;
    else
        newN = (n % 10) * 10 + (n % 10 + n / 10) % 10;

    while (newN != n)
    {
        if (newN < 10)
            newN = newN + 10 * newN;
        else
            newN = (newN % 10) * 10 + (newN % 10 + newN / 10) % 10;
        count++;
    }
    printf("%d", count);
}
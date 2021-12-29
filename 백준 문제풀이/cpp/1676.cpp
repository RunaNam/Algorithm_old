#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
    int a;
    int result = 0;
    scanf("%d", &a);
    for (int i = 2; i <= a; i++)
    {
        if (i % 5 == 0)
            result++;
        if (i % 25 == 0)
            result++;
        if (i % 125 == 0)
            result++;
    }

    printf("%d", result);
    return 0;
}

// ver.2

int main(void)
{
    int ans = 0;
    int n;
    scanf("%d", &n);
    for (int i =5; i<= n; i*= 5){
        ans += n/i;
    }
    
    printf("%d", ans);
    return 0;
}
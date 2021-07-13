#include <stdio.h>

using namespace std;

int f[21] = {
    0,
    1,
    1,
};

void fibonacci(int n)
{
    for (int i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    fibonacci(n);
    printf("%d", f[n]);
}
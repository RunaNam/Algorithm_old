#include <iostream>
#include <algorithm>
using namespace std;

int a[51];
int b[51];

int main()
{
    int n;
    int sum = 0;
    scanf("%d", &n);
    for (int j = 0; j < n; j++)
    {
        scanf("%d", &a[j]);
    }
    for (int j = 0; j < n; j++)
    {
        scanf("%d", &b[j]);
    }
    sort(a, a + n);
    sort(b, b + n);

    for (int j = 0; j < n; j++)
    {
        sum += a[j] * b[n - j - 1];
    }
    printf("%d", sum);
}
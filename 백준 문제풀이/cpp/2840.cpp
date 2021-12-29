#include <iostream>
using namespace std;

char wheel[26] = {
    '?',
};

int main()
{
    int n, k;
    int cnt = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++)
    {
        int a;
        char b;
        scanf("%d %c", &a, &b);
        cnt += a;
        while (cnt > n)
            cnt -= n;
        wheel[cnt] = b;
    }
    for (int i = 0; i < n; i++)
    {
        cnt += i;
        if (cnt > n)
            cnt -= n;
        printf("%c", wheel[cnt]);
    }
}
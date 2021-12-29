#include <iostream>
using namespace std;
long long memory[101] = {
    0,
    1,
    1,
    1,
    2,
    2,
};

void makecase(void)
{
    for (int i = 6; i <= 100; i++)
    {
        memory[i] = memory[i - 1] + memory[i - 5];
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    makecase();
    while (n--)
    {
        int a;
        scanf("%d", &a);
        printf("%lld\n", memory[a]);
    }
    return 0;
}
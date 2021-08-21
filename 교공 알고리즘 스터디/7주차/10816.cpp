#include <cstdio>
#include <unordered_map>

using namespace std;

unordered_map<int, int> m;

int main()
{
    int n, num, a;
    scanf("%d", &n);

    while (n--)
    {
        scanf("%d", &a);
        m[a]++;
    }

    scanf("%d", &num);
    while (num--)
    {
        scanf("%d", &a);
        printf("%d ", m[a]);
    }

    return 0;
}
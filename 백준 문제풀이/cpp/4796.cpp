#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int L, P, V;
    int count = 1;

    while (true)
    {
        scanf("%d %d %d", &L, &P, &V);
        if (L == 0 || P == 0 || V == 0)
            break;
        printf("Case %d: %d\n", count++, ((V / P) * L + min(V % P, L)));
    }
}
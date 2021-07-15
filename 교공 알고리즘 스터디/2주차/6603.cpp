#include <stdio.h>
#include <vector>

using namespace std;

vector<int> v(13);
vector<int> result(6);
int k;

void lotto(int start, int num)
{
    if (num == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            printf("%d ", result[i]);
        }
        printf("\n");
        return;
    }
    else
    {
        for (int i = start; i < k; i++)
        {
            result[num] = v[i];
            lotto(i + 1, num + 1);
        }
    }
}

int main()
{
    while (true)
    {
        scanf("%d", &k);
        if (k == 0)
            break;
        for (int i = 0; i < k; i++)
        {
            scanf("%d", &v[i]);
        }
        lotto(0, 0);
        printf("\n");
    }
}
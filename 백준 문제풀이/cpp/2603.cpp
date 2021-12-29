#include <cstdio>
using namespace std;
int num;
int arr[128][128];
int blue = 0;
int white = 0;

int search(int r1, int r2, int c1, int c2)
{
    int result = arr[r1][c1];

    for (int i = r1; i < r2; i++)
    {
        for (int j = c1; j < c2; j++)
        {

            if (arr[i][j] != result)
                return -1;
        }
    }
    if (result == 1)
        blue++;
    if (result == 0)
        white++;

    return 1;
}

void paper(int r1, int r2, int c1, int c2)
{
    if (search(r1, r2, c1, c2) == -1)
    {
        paper(r1, (r1 + r2) / 2, c1, (c1 + c2) / 2);
        paper((r1 + r2) / 2, r2, c1, (c1 + c2) / 2);
        paper(r1, (r1 + r2) / 2, (c1 + c2) / 2, c2);
        paper((r1 + r2) / 2, r2, (c1 + c2) / 2, c2);
    }
}

int main(void)
{
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    paper(0, num, 0, num);
    printf("%d\n%d", white, blue);
}
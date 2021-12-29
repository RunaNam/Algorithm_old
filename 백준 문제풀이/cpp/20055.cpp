#pragma warning(disable : 4996)
#include <cstdio>
#include <algorithm>

using namespace std;

struct bottom
{
    int num;
    int robot;
};
bottom conveyor[201], temp[201];

int main()
{
    int n, k;
    int cnt = 0;
    int result = 0;
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= 2 * n; i++)
    {
        scanf("%d", &conveyor[i].num);
        conveyor[i].robot = 0;
    }

    while (cnt < k)
    {
        result++;
        // 한칸 회전
        temp[1] = conveyor[2 * n];
        for (int i = 2; i <= n * 2; i++)
            temp[i] = conveyor[i - 1];
        for (int i = 1; i <= 2 * n; i++)
            conveyor[i] = temp[i];

        if (conveyor[n].robot)
            conveyor[n].robot = 0;

        //로봇 이동.
        for (int i = n - 1; i >= 1; i--)
        {
            if (conveyor[i].robot)
            {
                if (!conveyor[i + 1].robot && conveyor[i + 1].num > 0)
                {
                    conveyor[i + 1].robot = conveyor[i].robot;
                    conveyor[i + 1].num--;
                    if (conveyor[i + 1].num == 0)
                        cnt++;
                    conveyor[i].robot = 0;
                }
            }
        }
        if (conveyor[n].robot)
            conveyor[n].robot = 0;

        // 로봇 올림
        if (conveyor[1].num > 0 && !conveyor[1].robot)
        {
            conveyor[1].robot = 1;
            conveyor[1].num--;
            if (conveyor[1].num == 0)
                cnt++;
        }
    }

    printf("%d", result);
}
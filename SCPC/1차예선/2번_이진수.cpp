#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int num, n, t;
vector<int> a;

vector<int> check()
{

    vector<int> b(n);
    int num = n - 1;

    for (int i = 0; i < t; i++)
    {
        if (a[i] == 1)
            b[i + t] = 1;
        if (a[num - i] == 1)
            b[num - i - t] = 1;
    }

    for (int i = t; i < n - t; i++)
    {
        if (a[i] == 1)
        {
            if (b[i - t] == 1)
                continue;
            else
            {
                if ((i + t + t < n && a[i + t + t] != 0) || i + t + t > num)
                    b[i + t] = 1;

                else
                    b[i - t] = 1;
            }
        }
    }
    return b;
}

int main(int argc, char **argv)
{
    scanf("%d", &num);
    for (int k = 0; k < num; k++)
    {
        scanf("%d %d", &n, &t);
        for (int i = 0; i < n; i++)
        {
            int tmp;
            scanf("%1d", &tmp);
            a.push_back(tmp);
        }
        vector<int> b = check();
        printf("Case #%d \n", k + 1);
        for (int i = 0; i < n; i++)
        {
            printf("%d", b[i]);
        }
        printf("\n");
        a.clear();
    }

    return 0;
}
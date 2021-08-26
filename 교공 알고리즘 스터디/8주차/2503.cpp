#include <cstdio>
#include <vector>
#include <string>

using namespace std;

vector<pair<int, pair<int, int>>> v;
int n, tmp, s, b;
int result = 0;

vector<bool> check(1000, true);

void init()
{
    for (int i = 123; i <= 987; i++)
    {
        string tmp = to_string(i);
        if (tmp[0] == tmp[1] || tmp[1] == tmp[2] || tmp[2] == tmp[0])
            check[i] = false;
        if (tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0')
            check[i] = false;
    }
}

int main()
{
    scanf("%d", &n);

    init();

    while (n--)
    {
        scanf("%d %d %d", &tmp, &s, &b);
        v.push_back({tmp, {s, b}});
    }

    for (int i = 0; i < v.size(); i++)
    {
        int num = v[i].first;
        int strike = v[i].second.first;
        int ball = v[i].second.second;

        string numString = to_string(num);

        for (int j = 123; j <= 987; j++)
        {
            int tmpStrike = 0;
            int tmpBall = 0;

            if (check[j] == true)
            {
                string tmpString = to_string(j);

                for (int k = 0; k < 3; k++)
                {
                    for (int z = 0; z < 3; z++)
                    {
                        if (k == z && numString[k] == tmpString[z])
                            tmpStrike++;
                        else if (k != z && numString[k] == tmpString[z])
                            tmpBall++;
                    }
                }
                if (strike != tmpStrike || ball != tmpBall)
                    check[j] = false;
            }
        }
    }

    for (int i = 123; i <= 987; i++)
    {
        if (check[i])
            result++;
    }
    printf("%d", result);

    return 0;
}
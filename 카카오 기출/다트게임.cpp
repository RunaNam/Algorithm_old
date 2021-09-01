#include <cstdio>
#include <vector>
#include <string>

using namespace std;
vector<int> v;

int solution(string dartResult)
{
    int tmp, size;
    int result = 0;

    for (int i = 0; i < dartResult.size(); i++)
    {
        tmp = dartResult[i++] - '0';

        if (dartResult[i] == '0')
        {
            tmp *= 10;
            i++;
        }
        if (dartResult[i] == 'D')
        {
            tmp *= tmp;
        }
        else if (dartResult[i] == 'T')
        {
            tmp = tmp * tmp * tmp;
        }
        v.push_back(tmp);

        if (dartResult[i + 1] != '*' && dartResult[i + 1] != '#')
        {
            continue;
        }
        else
        {
            if (dartResult[i + 1] == '*')
            {
                if (v.size() == 1)
                {
                    v[0] = v[0] * 2;
                }
                else
                {
                    size = v.size();
                    v[size - 1] = v[size - 1] * 2;
                    v[size - 2] = v[size - 2] * 2;
                }
            }
            else
            {
                size = v.size();
                v[size - 1] = -v[size - 1];
            }
            i++;
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        result += v[i];
    }
    return result;
}

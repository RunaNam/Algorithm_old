#include <unordered_map>
#include <string>
#include <cctype>

using namespace std;
unordered_map<string, int> m1;
unordered_map<string, int> m2;

int solution(string str1, string str2)
{
    int a = 0; // 교집합
    int b = 0; // 합집합
    float div;

    for (int i = 0; i < str1.size() - 1; i++)
    {
        if (isalpha(str1[i]) && isalpha(str1[i + 1]))
        {
            string tmp;
            tmp += toupper(str1[i]);
            tmp += toupper(str1[i + 1]);

            m1[tmp]++;
        }
    }

    for (int i = 0; i < str2.size() - 1; i++)
    {
        if (isalpha(str2[i]) && isalpha(str2[i + 1]))
        {
            string tmp;
            tmp += toupper(str2[i]);
            tmp += toupper(str2[i + 1]);
            m2[tmp]++;
        }
    }

    for (auto i = m1.begin(); i != m1.end(); i++)
    {
        auto check = m2.find(i->first);
        if (check != m2.end())
        {
            if (check->second > i->second)
            {
                a += i->second;
                b += check->second;
            }
            else
            {
                a += check->second;
                b += i->second;
            }
        }
        else
        {
            b += i->second;
        }
    }

    for (auto i = m2.begin(); i != m2.end(); i++)
    {
        auto check = m1.find(i->first);
        if (check == m1.end())
        {
            b += i->second;
        }
    }

    if (a != b)
    {
        div = (float)a / (float)b;
    }
    else
    {
        div = 1;
    }

    int result = div * 65536;

    return result;
}
#include <string>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

string convert_num(int num, int n)
{
    char code[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    string tmp = "";
    int result;

    while (num / n != 0)
    {
        tmp = code[num % n] + tmp;
        num = num / n;
    }
    tmp = code[num % n] + tmp;
    return tmp;
}

bool is_prime(string s)
{
    // 여기에서 시간 좀 잡아먹음. int가 아닌 longlong으로 처리할 것.
    long long num = stoll(s);
    if (num < 2)
        return false;
    int a = (int)sqrt(num);
    for (int i = 2; i <= a; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int solution(int n, int k)
{
    string num = convert_num(n, k);
    int answer = 0;
    string tmp = "";

    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] == '0')
        {
            if (tmp.size() > 0 && is_prime(tmp))
            {
                answer++;
            }
            tmp = "";
        }
        else
        {
            tmp += num[i];
        }
    }

    if (tmp.size() > 0 && is_prime(tmp))
    {
        answer++;
    }

    return answer;
}
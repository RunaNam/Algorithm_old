#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string cache[102][102];

string bigNumAdd(const string a, const string b)
{
    long long sum = 0;
    string result;
    string copy1(a), copy2(b);

    while (!copy1.empty() || !copy2.empty() || sum)
    {
        if (!copy1.empty())
        {
            sum += copy1.back() - '0';
            copy1.pop_back();
        }
        if (!copy2.empty())
        {
            sum += copy2.back() - '0';
            copy2.pop_back();
        }
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

string combination(int n, int m)
{
    string &result = cache[n][m];
    if (n == m || m == 0)
        return "1";

    if (result != "")
        return result;

    result = bigNumAdd(combination(n - 1, m - 1), combination(n - 1, m));

    return result;
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%s", combination(n, m).c_str());
    return 0;
}
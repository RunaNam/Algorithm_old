#include <iostream>
#include <string>
#include <vector>

using namespace std;
string s;
vector<char> v;

long long result = 0;
int tmp = 1;
bool impossible = false;

void check()
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            tmp *= 2;
            v.push_back('(');
        }
        else if (s[i] == '[')
        {
            tmp *= 3;
            v.push_back('[');
        }
        else if (s[i] == ')' && (v.empty() || v.back() != '('))
        {
            impossible = true;
            break;
        }
        else if (s[i] == ']' && (v.empty() || v.back() != '['))
        {
            impossible = true;
            break;
        }
        else if (s[i] == ')')
        {
            if (s[i - 1] == '(')
                result += tmp;
            v.pop_back();
            tmp /= 2;
        }
        else if (s[i] == ']')
        {
            if (s[i - 1] == '[')
                result += tmp;
            v.pop_back();
            tmp /= 3;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    check();
    if (impossible || !v.empty())
    {
        cout << 0;
    }
    else
    {
        cout << result;
    }
    return 0;
}
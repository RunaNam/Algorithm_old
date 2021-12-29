#include <iostream>
#include <string>
#include <cstdio>
#include <stack>
using namespace std;

int precedence(char ch)
{
    if (ch == '(')
        return 0;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 2;
}

int main(void)
{
    string Str;
    cin >> Str;
    stack<char> s;

    for (char x : Str)
    {
        if (x >= 'A' && x <= 'Z')
        {
            printf("%c", x);
        }
        else if (x == '(')
        {
            s.push(x);
        }
        else if (x == ')')
        {
            while (!s.empty())
            {
                char op = s.top();
                s.pop();
                if (op == '(')
                    break;
                printf("%c", op);
            }
        }

        else
        {
            while (!s.empty() && precedence(s.top()) >= precedence(x))
            {
                printf("%c", s.top());
                s.pop();
            }
            s.push(x);
        }
    }

    while (!s.empty())
    {
        printf("%c", s.top());
        s.pop();
    }
    return 0;
}
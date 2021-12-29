#include <iostream>
#include <string>
#include <stack>
#include <cstdio>
using namespace std;

int main(void)
{
    string S;
    stack<char> s_stack;
    bool pass = false;
    bool type = false;

    getline(cin, S);

    for (char x : S)
    {
        if (x == '<')
        {
            while (!s_stack.empty())
            {

                printf("%c", s_stack.top());
                s_stack.pop();
            }
            pass = true;
            printf("%c", x);
        }

        else if (x == '>')
        {
            pass = false;
            printf("%c", x);
        }

        else if (pass == false && x == ' ')
        {
            while (!s_stack.empty())
            {
                printf("%c", s_stack.top());
                s_stack.pop();
            }
            printf(" ");
        }

        else if (pass == false)
            s_stack.push(x);

        else if (pass)
            printf("%c", x);
    }
    while (!s_stack.empty())
    {

        printf("%c", s_stack.top());
        s_stack.pop();
    }
    return 0;
}
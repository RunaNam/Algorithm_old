#pragma warning(disable : 4996)
#include <iostream>
#include <stack>
#include <cstdio>
#include <cstring>

using namespace std;
char a[600000];
int main(void)
{
    char x;
    int num;
    scanf("%s", a);
    stack<char> left, right;
    for (int i = 0; i < strlen(a); i++)
    {
        left.push(a[i]);
    }
    scanf("%d", &num);

    while (num--)
    {
        char command;
        scanf(" %c", &command);
        if (command == 'P')
        {
            scanf(" %c", &x);
            left.push(x);
        }
        else if (command == 'L')
        {
            if (!left.empty())
            {
                right.push(left.top());
                left.pop();
            }
        }
        else if (command == 'D')
        {
            if (!right.empty())
            {
                left.push(right.top());
                right.pop();
            }
        }
        else if (command == 'B')
        {
            if (!left.empty())
            {
                left.pop();
            }
        }
    }
    while (!left.empty())
    {
        right.push(left.top());
        left.pop();
    }
    while (!right.empty())
    {
        printf("%c", right.top());
        right.pop();
    }
    return 0;
}
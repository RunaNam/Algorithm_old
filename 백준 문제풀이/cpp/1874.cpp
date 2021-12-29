#include <iostream>
#include <stack>
#include <string>
#include <stdio.h>

using namespace std;

int main(void)
{
    int num;
    int x;
    stack<int> s;
    int top = 0;
    string ans;

    cin >> num;
    while (num--)
    {
        cin >> x;
        if (x > top)
        {
            while (x > top)
            {
                s.push(++top);
                ans += '+';
            }
            s.pop();
            ans += '-';
        }
        else
        {
            bool find = false;
            if (!s.empty())
            {
                int top = s.top();
                s.pop();
                ans += '-';
                if (x == top)
                {
                    find = true;
                }
            }
            if (!find)
            {
                printf("NO\n");
                return 0;
            }
        }
    }
    for (char x : ans)
    {
        printf("%c\n", x);
    }
    return 0;
}
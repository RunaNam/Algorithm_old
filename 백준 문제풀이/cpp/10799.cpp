#include <iostream>
#include <cstdio>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
    string s;
    int stack_num = 0;
    int result = 0;
    stack<int> s_stack;
    getline(cin, s);
    for (char x : s)
    {
        if (x == '(')
        {
            s_stack.push(stack_num);
        }
        else if (x == ')')
        {
            if (s_stack.top() == stack_num - 1)
            {
                result += s_stack.size() - 1;
            }
            else
                result++;
            s_stack.pop();
        }
        stack_num++;
    }
    printf("%d", result);
}
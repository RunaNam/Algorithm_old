#include <iostream>
#include <string>
#include <cstdio>
#include <stack>
using namespace std;

int main(void)
{
    int a;
    int operand[26];
    string Str;
    stack<double> S;
    scanf("%d", &a);
    cin >> Str;
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &operand[i]);
    }

    for (char x : Str)
    {
        if (x >= 'A' && x <= 'Z')
        {
            S.push((double)operand[x - 'A']);
        }
        else
        {
            double op2 = S.top();
            S.pop();
            double op1 = S.top();
            S.pop();
            if (x == '*')
                S.push(op1 * op2);
            else if (x == '/')
                S.push(op1 / op2);
            else if (x == '-')
                S.push(op1 - op2);
            else if (x == '+')
                S.push(op1 + op2);
            ;
        }
    }
    printf("%.2lf", S.top());
    return 0;
}
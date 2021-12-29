#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(void)
{
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
    {
        if ('a' <= s[i] && s[i] <= 'z')
        {
            if (s[i] <= 'm')
                s[i] += 13;
            else
                s[i] -= 13;
        }
        else if ('A' <= s[i] && s[i] <= 'Z')
        {
            if (s[i] <= 'M')
                s[i] += 13;
            else
                s[i] -= 13;
        }
    }
    cout << s;
}

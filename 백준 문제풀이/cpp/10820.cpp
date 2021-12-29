#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(void)
{
    while (true)
    {
        int sl = 0;
        int cl = 0;
        int num = 0;
        int space = 0;
        string s;
        getline(cin, s);

        if (s.empty())
            break;

        for (char x : s)
        {
            if ('a' <= x && x <= 'z')
                sl++;
            else if ('A' <= x && x <= 'Z')
                cl++;
            else if (x == ' ')
                space++;
            else
                num++;
        }
        printf("%d %d %d %d\n", sl, cl, num, space);
    }
    return 0;
}
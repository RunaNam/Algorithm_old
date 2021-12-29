#include <iostream>
#include <string>
using namespace std;

int X1;
int Y1;
int X2;
int Y2;
int cnt;
char a1;
char a2;

bool RangeCheck(int x, int y)
{
    if (x < 0 || y < 1 || x > 7 || y > 8)
        return false;
    return true;
}

bool SamePosition()
{
    if (X1 == X2 && Y1 == Y2)
        return true;
    return false;
}

void chess(string s)
{

    if (s[0] == 'L')
    {
        if (s.size() == 2)
        {
            if (s[1] == 'T')
            {
                if (X1 != 0 && Y1 != 8)
                {
                    X1--;
                    Y1++;
                }
                if (SamePosition())
                {
                    if (RangeCheck(X2 - 1, Y2 + 1))
                    {
                        X2--;
                        Y2++;
                    }
                    else
                    {
                        X1++;
                        Y1--;
                    }
                }
            }
            else
            {
                if (X1 != 0 && Y1 != 1)
                {
                    X1--;
                    Y1--;
                }
                if (SamePosition())
                {
                    if (RangeCheck(X2 - 1, Y2 - 1))
                    {
                        X2--;
                        Y2--;
                    }
                    else
                    {
                        X1++;
                        Y1++;
                    }
                }
            }
        }
        else
        {
            if (X1 != 0)
            {
                X1--;
            }
            if (SamePosition())
            {
                if (RangeCheck(X2 - 1, Y2))
                {
                    X2--;
                }
                else
                {
                    X1++;
                }
            }
        }
    }

    else if (s[0] == 'R')
    {
        if (s.size() == 2)
        {
            if (s[1] == 'T')
            {
                if (X1 != 7 && Y1 != 8)
                {
                    X1++;
                    Y1++;
                }
                if (SamePosition())
                {
                    if (RangeCheck(X2 + 1, Y2 + 1))
                    {
                        X2++;
                        Y2++;
                    }
                    else
                    {
                        X1--;
                        Y1--;
                    }
                }
            }
            else
            {
                if (X1 != 7 && Y1 != 1)
                {
                    X1++;
                    Y1--;
                }
                if (SamePosition())
                {
                    if (RangeCheck(X2 + 1, Y2 - 1))
                    {
                        X2++;
                        Y2--;
                    }
                    else
                    {
                        X1--;
                        Y1++;
                    }
                }
            }
        }
        else
        {
            if (X1 != 7)
            {
                X1++;
            }
            if (SamePosition())
            {
                if (RangeCheck(X2 + 1, Y2))
                {
                    X2++;
                }
                else
                {
                    X1--;
                }
            }
        }
    }

    else if (s[0] == 'T')
    {
        if (Y1 != 8)
        {
            Y1++;
        }
        if (SamePosition())
        {

            if (RangeCheck(X2, Y2 + 1))
            {
                Y2++;
            }
            else
            {
                Y1--;
            }
        }
    }

    else
    {
        if (Y1 != 1)
        {
            Y1--;
        }
        if (SamePosition())
        {
            if (RangeCheck(X2, Y2 - 1))
            {
                Y2--;
            }
            else
            {
                Y1++;
            }
        }
    }
}

int main()
{

    scanf("%c%d", &a1, &Y1);
    scanf("%c%c%d", &a2, &a2, &Y2);
    scanf("%d", &cnt);

    X1 = a1 - 'A';
    X2 = a2 - 'A';

    for (int i = 0; i < cnt; i++)
    {
        string s;
        cin >> s;
        chess(s);
    }
    printf("%c%d\n%c%d", X1 + 'A', Y1, X2 + 'A', Y2);
}
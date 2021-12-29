#include <iostream>
using namespace std;

int n;
int room[101][101] = {
    0,
};

void check()
{
    int mycount, vcount, hcount;
    vcount = 0;
    hcount = 0;

    for (int i = 0; i < n; i++)
    {
        mycount = 0;
        for (int j = 0; j < n; j++)
        {
            if (room[i][j])
                mycount++;
            else
                mycount = 0;
            if (mycount == 2)
            {
                vcount++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        mycount = 0;
        for (int j = 0; j < n; j++)
        {
            if (room[j][i])
                mycount++;
            else
                mycount = 0;
            if (mycount == 2)
            {
                hcount++;
            }
        }
    }
    printf("%d %d", vcount, hcount);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char b;
        scanf("%c", &b);
        for (int j = 0; j < n; j++)
        {
            char a;
            scanf("%c", &a);
            if (a == '.')
            {
                room[i][j] = 1;
            }
            else
            {
                room[i][j] = 0;
            }
        }
    }
    check();
}
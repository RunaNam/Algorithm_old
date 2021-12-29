#include <iostream>
using namespace std;

int n;
int room[101][101] = {
    0,
};

int check()
{
    int mycount, vcount, hcount;

    for (int i = 0; i < n; i++)
    {
        mycount = 0;
        vcount = 0;
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
        hcount = 0;
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
    printf("%d %d", hcount, vcount);
}

main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
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
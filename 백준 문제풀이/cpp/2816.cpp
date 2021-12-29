#include <iostream>
#include <string>
using namespace std;
string chan[101];

int main(void)
{
    int n;
    int pos1 = -1;
    int pos2 = -1;
    int arrange = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> chan[i];
    }

    if (n == 2)
    {
        printf("3");
        return 0;
    }

    for (int i = 1; i < n; i++)
    {
        if (chan[i] == "KBS1")
        {
            pos1 = i;
        }
        if (chan[i] == "KBS2")
        {
            pos2 = i;
        }
        if (pos1 != -1 && pos2 != -1)
        {
            break;
        }
    }
    if (pos1 > pos2)
    {
        arrange = 1;
    }
    for (int i = 0; i < pos1; i++)
    {
        printf("1");
    }
    for (int i = 0; i < pos1; i++)
    {
        printf("4");
    }
    for (int i = 0; i < pos2 + arrange; i++)
    {
        printf("1");
    }
    for (int i = 0; i < pos2 + arrange - 1; i++)
    {
        printf("4");
    }
}
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int color[4];
int number[10] = {
    0,
};
bool isContinue = false; //연속적인지
bool fiveColor;          //색 5개인지
bool threeColor;         //색 3개인지
int fourValue = 0;       //4개가 같은 값
int threeValue = 0;      //3개가 같은 값
int twoValue = 0;        //2개가 같은 값
int twoValueSmall = 0;
int maxNum = 0;
int ans = 0;

void numcheck()
{
    for (int i = 1; i < 10; i++)
    {
        if (number[i] == 4)
            fourValue = i;
        else if (number[i] == 3)
            threeValue = i;
        else if (number[i] == 2)
        {
            if (twoValue != 0)
            {
                twoValueSmall = twoValue;
                twoValue = i;
            }
            else
                twoValue = i;
        }
    }
}

void colorcheck()
{
    for (int i = 0; i < 4; i++)
    {
        if (color[i] == 5)
            fiveColor = true;
    }
}

void continuous()
{
    int count = 0;
    if (fourValue == 0 && threeValue == 0 && twoValue == 0)
    {
        for (int i = maxNum; i >= maxNum - 4; i--)
        {
            if (number[i] == 1)
                count++;
        }
    }
    if (count == 5)
        isContinue = true;
}

int main(void)
{
    for (int i = 0; i < 5; i++)
    {
        int n;
        char c;
        scanf(" %1c %d", &c, &n);
        switch (c)
        {
        case 'R':
            color[0]++;
            break;
        case 'Y':
            color[1]++;
            break;
        case 'B':
            color[2]++;
            break;
        case 'G':
            color[3]++;
            break;
        }
        number[n]++;
        maxNum = max(maxNum, n);
    }

    numcheck();
    colorcheck();
    continuous();

    if (fiveColor && isContinue)
    {
        ans = 900 + maxNum;
    }
    else if (fourValue != 0)
    {
        ans = 800 + fourValue;
    }
    else if ((threeValue != 0) && (twoValue != 0))
    {
        ans = (threeValue * 10) + twoValue + 700;
    }
    else if (fiveColor)
    {
        ans = 600 + maxNum;
    }
    else if (isContinue)
    {
        ans = 500 + maxNum;
    }
    else if (threeValue != 0)
    {
        ans = 400 + threeValue;
    }
    else if (twoValueSmall != 0)
    {
        ans = (twoValueSmall + 300) + (twoValue * 10);
    }
    else if (twoValue != 0)
    {
        ans = 200 + twoValue;
    }
    else
    {
        ans = 100 + maxNum;
    }

    printf("%d", ans);
    return 0;
}
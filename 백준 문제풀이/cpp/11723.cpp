#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int num;
bool a[21];

void func(string s, int n)
{
    if (s == "add")
    {
        if (a[n] == false)
            a[n] = true;
    }
    else if (s == "remove")
    {
        if (a[n] == true)
            a[n] = false;
    }
    else if (s == "check")
    {

        if (a[n] == true)
            printf("1\n");
        else
            printf("0\n");
    }
    else if (s == "toggle")
    {
        if (a[n] == true)
            a[n] = false;
        else
            a[n] = true;
    }
    else if (s == "all")
    {
        for (int i = 1; i <= 20; i++)
        {
            a[i] = true;
        }
    }
    else if (s == "empty")
    {
        for (int i = 1; i <= 20; i++)
        {
            a[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> num;
    for (int i = 1; i <= 20; i++)
    {
        a[i] = false;
    }

    for (int i = 0; i < num; i++)
    {
        string s;
        int n;
        cin >> s;
        if (s == "empty" || s == "all")
            func(s, 0);
        else
        {
            cin >> n;
            func(s, n);
        }
    }
}
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(void)
{
    string s;
    cin >> s;
    int arr[26];
    for (int i = 0; i < 26; i++)
    {
        arr[i] = -1;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (arr[i] == -1)
            arr[s[i] - 'a'] = i;
    }
    for (int i = 0; i < 26; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
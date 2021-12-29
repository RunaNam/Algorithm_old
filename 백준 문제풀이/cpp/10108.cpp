#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(void)
{
    int arr[26] = {0};

    string s;
    cin >> s;
    for (char x : s)
    {
        arr[x - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1001];

int main()
{
    int num, min;
    int result = 0;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + num);
    for (int i = 0; i < num; i++)
    {
        result += (num - i) * arr[i];
    }
    printf("%d", result);
}
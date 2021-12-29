#include <cstdio>
#include <queue>
using namespace std;
int main(void)
{
    int a, b;
    int i;
    queue<int> table;
    scanf("%d %d", &a, &b);
    for (i = 1; i <= a; i++)
    {
        table.push(i);
    }
    printf("<");
    while (!table.empty())
    {
        for (i = 1; i < b; i++)
        {
            table.push(table.front());
            table.pop();
        }
        int result = table.front();
        table.pop();
        printf("%d", result);
        if (!table.empty())
        {
            printf(", ");
        }
    }
    printf(">");
    return 0;
}
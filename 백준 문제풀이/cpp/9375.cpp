#include <iostream>
#include <string>
#include <map>
using namespace std;
string memory[31][2];
map<int, string> m;

void makecase(int a)
{
    for (int i = 0; i < a; i++)
    {
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    makecase();
    while (n--)
    {
        int a;
        scanf("%d", &a);
        for (int i = 0; i < a; i++)
        {
            scanf("%s %s", memory[i][0], memory[i][1]);
        }
        count(a);
    }
    return 0;
}
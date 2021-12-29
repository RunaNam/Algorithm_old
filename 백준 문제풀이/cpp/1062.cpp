#include <iostream>
#include <stack>
#include <string>
using namespace std;

char first[] = "antic";
stack<char> s;
s.push('a');
s.push('n');
s.push('t');
s.push('i');
s.push('c');

int main()
{
    int n, k;
    int count = 0;
    scanf("%d %d", &n, &k);
    if (k > 5)
    {
        for (int i = 0; i < n; i++)
        {
            string a;
            scanf("%s", &a);
            if (a.length() == 8)
                count++;
            printf("%d", a.length());
            // for (int j = 0; j<a.length()-8; )
        }
    }
    print("%d", count);
}
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int max_value = -2000000000;
int min_value = 2000000000;

void calculate(int pos, vector<int> a, int my_operator[], int result)
{
    if (pos == a.size())
    {
        min_value = min(min_value, result);
        max_value = max(max_value, result);
        return;
    }
    if (my_operator[0] > 0)
    {
        my_operator[0]--;
        calculate(pos + 1, a, my_operator, result + a[pos]);
        my_operator[0]++;
    }
    if (my_operator[1] > 0)
    {
        my_operator[1]--;
        calculate(pos + 1, a, my_operator, result - a[pos]);
        my_operator[1]++;
    }
    if (my_operator[2] > 0)
    {
        my_operator[2]--;
        calculate(pos + 1, a, my_operator, result * a[pos]);
        my_operator[2]++;
    }
    if (my_operator[3] > 0)
    {
        my_operator[3]--;
        calculate(pos + 1, a, my_operator, result / a[pos]);
        my_operator[3]++;
    }
}

int main()
{
    int n;
    vector<int> a;
    int my_operator[4];

    scanf("%d", &n);
    while (n--)
    {
        int tmp;
        scanf("%d", &tmp);
        a.push_back(tmp);
    }
    scanf("%d %d %d %d", &my_operator[0], &my_operator[1], &my_operator[2], &my_operator[3]);

    calculate(1, a, my_operator, a[0]);

    printf("%d\n%d", max_value, min_value);
}
#include <cstdio>

#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int n, tmp, result;
    vector<int> v;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &tmp);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    tmp = 0;
    result = tmp;
    for (int i = 0; i < v.size(); i++)
    {
        tmp += v[i];
        result += tmp;
    }
    printf("%d", result);
}

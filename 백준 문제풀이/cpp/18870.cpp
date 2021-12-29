#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> v, idx;

int main(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        v.push_back(a);
        idx.push_back(a);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

    for (int a : idx)
    {
        int pos = lower_bound(v.begin(), v.end(), a) - v.begin();
        printf("%d ", pos);
    }
}
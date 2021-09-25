#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    int n, x;
    int left, right;
    int answer = 0;
    vector<int> v;
    scanf("%d", &n);
    while (n--)
    {
        int tmp;
        scanf("%d", &tmp);
        v.push_back(tmp);
    }
    scanf("%d", &x);

    sort(v.begin(), v.end());
    left = 0;
    right = v.size() - 1;

    while (left < right)
    {
        int sum = v[left] + v[right];

        if (sum == x)
        {
            answer++;
            left++;
            right--;
        }
        else if (sum < x)
            left++;
        else
            right--;
    }

    printf("%d", answer);
}
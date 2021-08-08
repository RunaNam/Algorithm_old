#include <cstdio>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> right;
priority_queue<int> left;

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int k;
        scanf("%d", &k);

        if (left.empty() && right.empty())
            left.push(k);
        else if (-2 < left.size() - right.size() && left.size() - right.size() < 2)
        {
            if (!left.empty() && left.top() < k)
                right.push(k);
            else
                left.push(k);
        }
        else
        {
            if (left.size() > right.size())
            {
                if (!left.empty() && left.top() < k)
                    right.push(k);
                else
                {
                    left.push(k);
                    int tmp = left.top();
                    left.pop();
                    right.push(tmp);
                }
            }
            else
            {
                if (!left.empty() && left.top() < k)
                {
                    right.push(k);
                    int tmp = right.top();
                    right.pop();
                    left.push(tmp);
                }
                else
                {
                    left.push(k);
                }
            }
        }
        printf("%d\n", left.top());
    }

    return 0;
}
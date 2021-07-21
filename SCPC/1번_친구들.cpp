#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> v[100000];
vector<bool> c(100000);
int T, n, d;
int cnt;

void find_friend(int start)
{
    queue<int> q;
    q.push(start);
    c[start] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < v[x].size(); i++)
        {
            int y = v[x][i];

            if (y < n && !c[y])
            {
                q.push(y);
                cnt--;
                c[y] = true;
            }
        }
    }
}

int main(int argc, char **argv)
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> d;
            v[j].push_back(d + j);

            if (d + j < n)
                v[d + j].push_back(j);
        }

        cnt = n;
        for (int k = 0; k < n; k++)
        {
            if (!c[k])
                find_friend(k);
        }
        cout << "Case #" << i + 1 << "\n";
        cout << cnt << '\n';
        for (int i = 0; i < n; i++)
        {
            v[i].clear();
            c[i] = false;
        }
    }

    return 0;
}
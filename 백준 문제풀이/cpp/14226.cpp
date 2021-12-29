#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int s;
bool v[2000][2000];

int bfs()
{
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(1, 0), 0));
    v[1][0] = true;
    while (!q.empty())
    {
        int pos = q.front().first.first;
        int clip = q.front().first.second;
        int count = q.front().second;
        q.pop();

        if (pos == s)
            return count;

        if (0 < pos && pos < 2000)
        {
            if (v[pos - 1][clip] == false)
            {
                q.push(make_pair(make_pair(pos - 1, clip), count + 1));
                v[pos - 1][clip] = true;
            }
            if (v[pos][pos] == false)
            {
                q.push(make_pair(make_pair(pos, pos), count + 1));
                v[pos][pos] = true;
            }
        }
        if (clip > 0 && pos + clip < 2000)
        {
            if (v[pos][pos + clip] == false)
            {
                q.push(make_pair(make_pair(pos + clip, clip), count + 1));
                v[pos + clip][pos] = true;
            }
        }
    }
}

int main()
{
    scanf("%d", &s);
    printf("%d", bfs());
}
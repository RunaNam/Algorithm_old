#pragma warning(disable : 4996)

#include <cstdio>
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int num, n, m, k, t1, t2;
deque<int> v[501];
deque<pair<int, int>> vk; // 간선 안정해진것들
bool visited[501];
vector<int> ans;
bool ok = false;

string toBinary(int n)
{
    string r;
    if (n == 0)
        return "0";
    while (n != 0)
    {
        r += (n % 2 == 0 ? "0" : "1");
        n /= 2;
    }
    return r;
}

void DFS(int a, int cnt)
{
    if (!(a == 1 && cnt == 0))
        visited[a] = true;

    for (int i = 0; i < v[a].size(); i++)
    {
        if (!visited[v[a][i]])
        {
            DFS(v[a][i], cnt + 1);
        }
    }
}

void check(int cnt)
{
    string bit = toBinary(cnt);
    for (int i = 0; i < k; i++)
    {
        if (bit[i] == '0' || bit.size() < i)
        {
            v[vk[i].first].push_back(vk[i].second);
            ans.push_back(0);
        }
        else
        {
            v[vk[i].second].push_back(vk[i].first);
            ans.push_back(1);
        }
    }

    DFS(1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            ok = true;
            break;
        }
    }

    if (!ok && cnt <= k)
    {
        ans.clear();

        ok = false;

        for (int i = 1; i <= n; i++)
        {
            visited[i] = false;
        }

        for (int i = 0; i < k; i++)
        {
            if (bit[i] == 1)
                v[vk[i].first].pop_back();
            else
                v[vk[i].second].pop_back();
        }
        check(cnt + 1);
    }
}

int main()
{
    scanf("%d", &num);
    for (int z = 0; z < num; z++)
    {
        scanf("%d %d %d", &n, &m, &k);

        for (int i = 0; i < m; i++)
        {
            scanf("%d %d", &t1, &t2);
            v[t1].push_back(t2);
        }

        for (int i = 0; i < k; i++)
        {
            scanf("%d %d", &t1, &t2);
            vk.push_back(make_pair(t1, t2));
        }

        check(0);

        printf("Case #%d \n", z + 1);
        for (int i = 0; i < k; i++)
        {
            printf("%d", ans[i]);
        }
        printf("\n");

        //초기화
        deque<pair<int, int>>().swap(vk);
        vector<int>().swap(ans);
        ok = false;
        for (int i = 1; i <= n; i++)
        {
            deque<int>().swap(v[i]);
            visited[i] = false;
        }
    }

    return 0;
}

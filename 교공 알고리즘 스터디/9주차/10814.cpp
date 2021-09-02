#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
vector<pair<int, string>> v;

bool check(pair<int, string> a, pair<int, string> b)
{
    return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, tmp;
    string s;

    cin >> n;

    while (n--)
    {
        cin >> tmp >> s;
        v.push_back({tmp, s});
    }

    stable_sort(v.begin(), v.end(), check);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
}

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(pair<string, int> a, pair<string, int> b)
{
    return a.second < b.second;
}

map<string, int> m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k, l;
    cin >> k >> l;
    for (int i = 0; i < l; i++)
    {
        string s;
        cin >> s;
        if (m.find(s) != m.end())
        {
            m.erase(s);
        }
        m.insert({s, i});
    }

    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), compare);

    auto iter = v.begin();

    while (k-- && iter != v.end())
    {
        cout << iter->first << '\n';
        iter++;
    }

    return 0;
}
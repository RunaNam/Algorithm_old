#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;

map<int, string> myMap;
map<string, int> myMap2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        myMap.insert({i + 1, s});
        myMap2.insert({s, i + 1});
    }

    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        if (!isdigit(s[0]))
        {
            cout << myMap2[s] << '\n';
        }
        else
        {
            int a = stoi(s);
            cout << myMap[a] << '\n';
        }
    }

    return 0;
}
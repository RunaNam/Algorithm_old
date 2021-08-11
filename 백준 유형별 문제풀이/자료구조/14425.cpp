#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> myMap;
int result = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        myMap.insert({t, 1});
    }

    for (int i = 0; i < m; i++)
    {
        string t2;
        cin >> t2;
        if (myMap.count(t2) == 1)
            result++;
    }

    cout << result;

    return 0;
}
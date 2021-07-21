#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool check(string s)
{
    vector<char> v;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            v.push_back(s[i]);
        }
        else if (s[i] == ')')
        {
            if (v.empty())
                return false;
            v.pop_back();
        }
    }
    if (!v.empty())
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    string s;

    cin >> n;
    while (n--)
    {
        cin >> s;
        if (check(s))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}

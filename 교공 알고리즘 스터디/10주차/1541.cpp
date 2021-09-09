#include <iostream>

#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    string tmp;
    vector<int> v;
    int result = 0;
    bool minus = false;

    cin >> s;

    for (int i = 0; i <= s.size(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '\0')
        {
            if (minus)
            {
                result -= stoi(tmp);
            }
            else
            {
                result += stoi(tmp);
            }
            tmp = "";
            if (s[i] == '-')
            {
                minus = true;
            }
        }
        else
        {
            tmp += s[i];
        }
    }

    cout << result;
}
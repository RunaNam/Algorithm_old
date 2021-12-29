#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int num1, num2, t;

bool check(vector<string> s, vector<string> tmp)
{
    vector<bool> visited(6, false);
    int cnt = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (!visited[j] && s[j] == tmp[i])
            {
                visited[j] = true;
                cnt++;
                break;
            }
        }

        string temp;
        for (int j = 0; j < 3; j++)
        {
            temp.push_back(tmp[j][i]);
        }
        for (int j = 0; j < 6; j++)
        {
            if (!visited[j] && temp == s[j])
            {
                visited[j] = true;
                cnt++;
                break;
            }
        }
    }
    return cnt == 6;
}

int main()
{
    vector<string> s(6);
    bool finish = false;

    for (int i = 0; i < 6; i++)
    {
        cin >> s[i];
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            for (int z = 0; z < 6; z++)
            {
                if (i == j || j == z || z == i)
                    continue;
                vector<string> tmp(3);
                tmp[0] = s[i];
                tmp[1] = s[j];
                tmp[2] = s[z];
                if (check(s, tmp))
                {
                    for (int k = 0; k < 3; k++)
                    {
                        cout << tmp[k] << '\n';
                    }
                    return 0;
                }
            }
        }
    }
    cout << '0';
}
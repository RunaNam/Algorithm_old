#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>

using namespace std;

vector<char> v;
deque<string> nums;
bool flow = true;
bool error = false;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    while (n--)
    {
        flow = true;
        error = false;
        string s;
        string arr;
        int cnt;
        cin >> s >> cnt >> arr;

        arr = arr.substr(1, arr.size() - 2);
        stringstream ss(arr);
        string tmp;

        while (getline(ss, tmp, ','))
        {
            nums.push_back(tmp);
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'R')
            {
                flow = !flow;
            }
            else
            {
                if (nums.size() == 0)
                {
                    cout << "error\n";
                    error = true;
                    break;
                }
                else
                {
                    if (flow)
                    {
                        nums.pop_front();
                    }
                    else
                    {
                        nums.pop_back();
                    }
                }
            }
        }

        if (!error)
        {

            cout << '[';
            if (flow)
            {
                while (!nums.empty())
                {
                    cout << nums.front();
                    nums.pop_front();
                    if (nums.size() != 0)
                        cout << ',';
                }
            }
            else
            {
                while (!nums.empty())
                {
                    cout << nums.back();
                    nums.pop_back();
                    if (nums.size() != 0)
                        cout << ',';
                }
            }
            cout << ']' << '\n';
        }
        nums.clear();
    }

    return 0;
}
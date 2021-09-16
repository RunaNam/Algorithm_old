#include <iostream>

#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    unordered_map<string, set<string>> m;
    unordered_map<string, int> mail;
    vector<int> answer;

    for (int i = 0; i < report.size(); i++)
    {
        stringstream ss;
        ss.str(report[i]);
        string a, b;
        ss >> a >> b;
        m[b].insert(a);
    }

    for (int i = 0; i < id_list.size(); i++)
    {
        if (m[id_list[i]].size() >= k)
        {
            for (auto iter = m[id_list[i]].begin(); iter != m[id_list[i]].end(); iter++)
            {
                mail[*iter]++;
            }
        }
    }

    for (int i = 0; i < id_list.size(); i++)
    {
        answer.push_back(mail[id_list[i]]);
    }

    return answer;
}

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++)
    {
        int first = commands[i][0] - 1;
        int end = commands[i][1];
        int idx = commands[i][2];

        vector<int> tmp;
        tmp.assign(array.begin() + first, array.begin() + end);
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[idx - 1]);
    }

    return answer;
}
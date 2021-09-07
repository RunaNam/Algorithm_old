#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;
    int size = prices.size();

    for (int i = 0; i < size; i++)
    {
        int cnt = 0;
        int tmp = prices[i];
        for (int j = i + 1; j < size; j++)
        {
            cnt++;
            if (prices[j] < tmp)
            {
                break;
            }
        }
        answer.push_back(cnt);
    }

    return answer;
}
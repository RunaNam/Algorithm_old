#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations)
{
    int answer = 0;

    sort(citations.begin(), citations.end(), greater<int>());

    // 제일 큰 값이 0이면 h-index는 0
    if (!citations[0])
        return 0;

    for (int i = 0; i < citations.size(); i++)
    {
        //h-index 범위
        if (citations[i] > i)
            answer++;
        // 벗어남
        else
            break;
    }

    return answer;
}
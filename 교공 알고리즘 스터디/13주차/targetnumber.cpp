#include <string>
#include <vector>

using namespace std;
int answer = 0;

void dfs(int a, vector<int> numbers, int target, int sum)
{
    if (a == numbers.size())
    {
        if (sum == target)
            answer++;
        return;
    }

    dfs(a + 1, numbers, target, sum - numbers[a]);
    dfs(a + 1, numbers, target, sum + numbers[a]);
}

int solution(vector<int> numbers, int target)
{
    dfs(0, numbers, target, 0);
    return answer;
}
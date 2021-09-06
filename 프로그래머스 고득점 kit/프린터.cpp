#include <vector>
#include <deque>

using namespace std;

bool check(vector<int> priorities)
{
    int first = priorities.front();

    for (int i = 1; i < priorities.size(); i++)
    {
        if (priorities[i] > first)
        {
            return false;
        }
    }

    return true;
}

int solution(vector<int> priorities, int location)
{

    int result = 1;
    while (!priorities.empty())
    {
        if (location == 0)
        {
            if (check(priorities))
            {
                return result;
            }
            else
            {
                priorities.push_back(priorities[0]);
                priorities.erase(priorities.begin());
                location = priorities.size() - 1;
            }
        }
        else
        {
            if (check(priorities))
            {
                priorities.erase(priorities.begin());
                result++;
            }
            else
            {
                priorities.push_back(priorities[0]);
                priorities.erase(priorities.begin());
            }
            location--;
        }
    }
}

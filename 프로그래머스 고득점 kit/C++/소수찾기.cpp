#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool visited[8] = {
    false,
};
vector<int> nums;

bool is_prime(int a)
{
    if (a < 2)
        return false;

    for (int i = 2; i * i < a; i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}

int solution(string numbers)
{
    int answer = 0;
    vector<int> num;
    set<int> all_num;
    int size = numbers.size();

    for (int i = 0; i < size; i++)
    {
        num.push_back(numbers[i] - '0');
        all_num.insert(numbers[i] - '0');
    }

    sort(num.begin(), num.end());

    do
    {
        for (int i = 2; i < size; i++)
        {
            string tmp = "";
            for (int j = 0; j < i; j++)
            {
                tmp += num[j] + '0';
            }
            all_num.insert(stoi(tmp));
        }
    } while (next_permutation(num.begin(), num.end()));

    for (int n : all_num)
    {
        if (is_prime(n))
            answer++;
    }

    return answer;
}

int main()
{
    solution("17");
}
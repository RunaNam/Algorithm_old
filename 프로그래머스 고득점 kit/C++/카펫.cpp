#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;

    //노란색의 약수페어를 찾고, 두 값에서 +2 해서 카펫 격자 개수하고 같은지 확인.
    // 두 변이 같은거까지는 굳이 필요 없어서 나감.
    for (int i = 1; i * i <= yellow; i++)
    {
        if (yellow % i == 0)
        {
            int a = yellow / i;
            if ((a + 2) * (i + 2) == brown + yellow)
            {
                answer.push_back(a + 2);
                answer.push_back(i + 2);
                break;
            }
        }
    }

    return answer;
}
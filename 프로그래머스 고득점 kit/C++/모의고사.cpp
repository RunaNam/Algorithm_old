#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int stu1[] = {1, 2, 3, 4, 5};
int stu2[] = {2, 1, 2, 3, 2, 4, 2, 5};
int stu3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    int score[3] = {
        0,
    };
    int biggest = 0;

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == stu1[i % 5])
            score[0]++;

        if (answers[i] == stu2[i % 8])
            score[1]++;

        if (answers[i] == stu3[i % 10])
            score[2]++;
    }

    // 최닷값 계산
    biggest = max(max(score[0], score[1]), score[2]);

    // 최닷값이랑 같은 수 push
    for (int i = 0; i < 3; i++)
    {
        if (score[i] == biggest)
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> s_numbers;

bool cmp(string a, string b)
{
    return a + b > b + a;
    // string 두개를 합쳐서 진행. ex) 610 , 106
}

string solution(vector<int> numbers)
{
    string answer = "";
    vector<string> temp;

    // string 값으로 저장.
    for (auto num : numbers)
        temp.push_back(to_string(num));

    sort(temp.begin(), temp.end(), cmp);

    //0일 경우
    if (temp.at(0) == "0")
        return "0";

    for (auto num : temp)
        answer += num;

    return answer;
}

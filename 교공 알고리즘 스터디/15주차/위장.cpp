#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    unordered_map<string, int> clothes_m;

    for (auto cloth : clothes)
    {
        clothes_m[cloth[1]]++;
    }

    for (auto spy_cloth : clothes_m)
    {
        answer *= spy_cloth.second + 1;
    }

    return answer - 1;
}
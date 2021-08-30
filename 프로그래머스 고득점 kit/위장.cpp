#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> phone_book)
{
    unordered_map<string, int> m;
    int result = 1;

    for (int i = 0; i < phone_book.size(); i++)
    {
        m[phone_book[i][1]]++;
    }

    for (auto i = m.begin(); i != m.end(); i++)
    {
        result *= (i->second + 1);
    }
    return result - 1;
}

int main()
{

    solution({{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}});

    return 0;
}
#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book)
{
    sort(phone_book.begin(), phone_book.end());
    int max = phone_book.size();
    for (int i = 0; i < max; i++)
    {
        int size = phone_book[i].size();
        string a = phone_book[i];

        for (int j = i + 1; j < max; j++)
        {
            if (phone_book[j][0] != phone_book[i][0])
                break;
            if (phone_book[j].size() < size)
                continue;
            string b = phone_book[j].substr(0, size);
            if (a.compare(b) < 0)
                break;
            else if (a.compare(b) == 0)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    //	solution({ "119", "97674223", "1195524421" });
    //	solution({ "123","456","789" });
    solution({"15", "123", "1235", "567", "88"});

    return 0;
}
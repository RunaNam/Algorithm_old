#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records)
{
    unordered_map<string, int> cars;
    map<string, int> price;
    vector<int> answer;

    for (int i = 0; i < records.size(); i++)
    {
        string tmp = records[i];

        string t = tmp.substr(0, 2);
        string m = tmp.substr(3, 2);
        string car = tmp.substr(6, 4);
        int time = stoi(t) * 60 + stoi(m);

        if (tmp[11] == 'I')
        {
            cars[car] = time;
        }
        else
        {
            price[car] += time - cars[car];
            cars[car] = -1;
        }
    }

    for (auto iter = cars.begin(); iter != cars.end(); iter++)
    {
        if (iter->second != -1)
        {
            price[iter->first] += 1439 - iter->second;
        }
    }

    for (auto iter = price.begin(); iter != price.end(); iter++)
    {
        int car_time = iter->second;

        if (car_time <= fees[0])
        {
            answer.push_back(fees[1]);
        }
        else
        {
            car_time -= fees[0];
            int over_time;

            if (car_time % fees[2] != 0)
            {
                over_time = car_time / fees[2] + 1;
            }
            else
            {
                over_time = car_time / fees[2];
            }

            answer.push_back(fees[1] + over_time * fees[3]);
        }
    }

    return answer;
}

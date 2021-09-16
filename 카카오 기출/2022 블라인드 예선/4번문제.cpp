#include <iostream>

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

vector<int> expected_arrow(11);
vector<vector<int>> s;

// 1은 쐈음 0은 안쐈음 -1은 아직 안셌음.
void shoot_arrows(int count, int arrows, vector<int> shoot)
{
    if (count == 11)
    {
        if (arrows == 0)
            s.push_back(shoot);
        if (arrows != 0)
        {
            shoot[10] = arrows;
            s.push_back(shoot);
        }
    }
    else
    {
        for (int i = count; i < 11; i++)
        {
            if (shoot[i] == -1)
            {
                if (expected_arrow[i] <= arrows)
                {
                    shoot[i] = expected_arrow[i];
                    shoot_arrows(count + 1, arrows - expected_arrow[i], shoot);
                }
                shoot[i] = 0;
                shoot_arrows(count + 1, arrows, shoot);
            }
        }
    }
}

bool sort_cmp(vector<int> a, vector<int> b)
{
    for (int i = 0; i < 11; i++)
    {
        return a[i] > b[i];
    }
}

int scoring(vector<int> lion, vector<int> peach)
{
    int Lscore = 0;
    int Pscore = 0;

    for (int i = 0; i < 10; i++)
    {
        if (lion[i] == 0 && peach[i] == 0)
            continue;
        else
        {
            if (lion[i] > peach[i])
                Lscore += 10 - i;
            else
                Pscore += 10 - i;
        }
    }

    if (Lscore > Pscore)
        return Lscore - Pscore;
    else
        return -1;
}

vector<int> solution(int n, vector<int> info)
{
    for (int i = 0; i < 10; i++)
    {
        expected_arrow[i] = info[i] + 1;
    }

    vector<int> tmp(11, -1);
    pair<int, vector<int>> p;
    p.first = -1;

    shoot_arrows(0, n, tmp);

    s.erase(unique(s.begin(), s.end()), s.end());

    sort(s.begin(), s.end(), sort_cmp);

    for (int i = 0; i < s.size(); i++)
    {
        int score = scoring(s[i], info);
        if (score != -1 && score >= p.first)
        {
            p.first = score;
            p.second = s[i];
        }
    }

    if (p.first == -1)
    {
        p.second.push_back(-1);
    }
    return p.second;
}
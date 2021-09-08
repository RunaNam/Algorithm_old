#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool compare_m2(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

bool compare_m(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> result;
    unordered_map<string, vector<pair<int, int>>> m;
    unordered_map<string, int> m2;
    vector<pair<string, int>> genre_play;

    for (int i = 0; i < genres.size(); i++)
    {
        m2[genres[i]] += plays[i];
        m[genres[i]].push_back({plays[i], i});
    }

    for (auto &play : m)
    {
        sort(play.second.begin(), play.second.end(), compare_m);
    }

    genre_play.assign(m2.begin(), m2.end());
    sort(genre_play.begin(), genre_play.end(), compare_m2);

    for (int i = 0; i < genre_play.size(); i++)
    {
        string name = genre_play[i].first;
        for (int j = 0; (j < m[name].size()) && (j < 2); j++)
        {
            result.push_back(m[name][j].second);
        }
    }

    return result;
}
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

bool cmp2(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    unordered_map<string, int> genre_plays;
    vector<pair<string, int>> genre_plays_v;

    unordered_map<string, vector<pair<int, int>>> genre_songs;

    for (int i = 0; i < genres.size(); i++)
    {
        genre_plays[genres[i]] += plays[i];
        genre_songs[genres[i]].push_back({i, plays[i]});
    }

    for (auto genre_play : genre_plays)
    {
        genre_plays_v.push_back(genre_play);
        sort(genre_songs[genre_play.first].begin(), genre_songs[genre_play.first].end(), cmp2);
    }

    sort(genre_plays_v.begin(), genre_plays_v.end(), cmp);

    for (auto genre_play_v : genre_plays_v)
    {
        answer.push_back(genre_songs[genre_play_v.first][0].first);
        if (genre_songs[genre_play_v.first].size() > 1)
            answer.push_back(genre_songs[genre_play_v.first][1].first);
    }

    return answer;
}
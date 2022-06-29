#include "베스트앨범.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

베스트앨범_BEGIN

bool cmp(pair<int, int> lhs, pair<int, int> rhs) {
    if (lhs.second > rhs.second) return true;
    else if (lhs.second == rhs.second)
        if (lhs.first < rhs.first) return true;
    return false;
}

bool cmpGenreCount(pair<string, int> lhs, pair<string, int> rhs) {
    if (lhs.second > rhs.second) return true;
    return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    // 자료구조 map을 사용한다.
    // 장르 별 노래 플레이 횟수를 map에 저장하고
    // 장르 별 속한 노래 번호들을 다른 map에 저장한다.
    // 저장한 데이터를 이용해 조건에 맞게 sorting한다.

    vector<int> answer;
    
    // <장르, 장르에 속한 노래들>
    map<string, vector<pair<int, int>>> genre_m;
    // 장르 별 노래 플레이 횟수 맵
    map<string, int> count_m;

    for (int i = 0; i < genres.size(); i++) {
        genre_m[genres[i]].emplace_back(i, plays[i]);
        count_m[genres[i]]+= plays[i];
    }

    for (auto genre : genre_m) {
        sort(genre_m[genre.first].begin(), genre_m[genre.first].end(), cmp);
    }

    vector<pair<string, int>> count_v;

    for (auto genre : count_m)
        count_v.emplace_back(genre);

    sort(count_v.begin(), count_v.end(), cmpGenreCount);

    for (pair<string, int> data : count_v) {

        string genre = data.first;
        vector<pair<int, int>> song_v = genre_m[genre];
        
        answer.push_back(song_v[0].first);

        if (song_v.size() >= 2)
            answer.push_back(song_v[1].first);
    }

    return answer;
}

void service() {

    vector<string> g = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> p = { 500, 600, 150, 800, 2500 };
    vector<int> ans = solution(g, p);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

베스트앨범_END
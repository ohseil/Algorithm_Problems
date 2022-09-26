#include "방금그곡.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

방금그곡_BEGIN

#define SatisfiedMusicInfo pair<int, pair<int, string>>

void eraseSharpInStr(string& str) {

    string erasedStr = "";

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '#')
            erasedStr[erasedStr.length() - 1] = tolower(erasedStr[erasedStr.length() - 1]);
        else
            erasedStr += str[i];
    }

    str = erasedStr;
}

int timeToMin(string time) {
    int hour = stoi(time.substr(0, 2));
    int min = stoi(time.substr(3));
    return hour * 60 + min;
}

string getPlayData(int& startTime, int& endTime, string& sheet) {

    string playData = "";
    int playTime = endTime - startTime;

    for (int i = 0; i < playTime; i++)
        playData += sheet[i % sheet.length()];

    return playData;
}

bool cmp(SatisfiedMusicInfo lhs, SatisfiedMusicInfo rhs) {
    if (lhs.second.first > rhs.second.first)
        return true;
    else if (lhs.second.first == rhs.second.first)
        if (lhs.first < rhs.first)
            return true;
    return false;
}

string solution(string m, vector<string> musicinfos) {
    
    // 악보에서 '#'이 붙은 음은 char형 2개가 붙은 형태이기 때문에 계산하기 어렵다.
    // 그래서 '#'이 붙은 음을 소문자로 바꿔서 계산하는 방법을 사용했다.
    // 이렇게 하면 모든 음을 char형 1개로 계산이 가능하다.

    // 각 음악마다 play time을 구해서 악보를 보고 play time 동안 나왔던
    // 음을 string 형으로 만들고 m이 포함되었는지 확인한다.

    // 조건이 맞으면 음악의 순서, play time, 음악 제목 데이터를 vector에 저장한다.
    // 문제의 조건에 맞게 정렬한다.

    string answer = "(None)";
    
    vector<SatisfiedMusicInfo> satisfiedMusicInfos;

    eraseSharpInStr(m);
    
    for (int i = 0; i < musicinfos.size(); i++) {

        string musicInfo = musicinfos[i];

        int startTime, endTime;
        string name, sheetMusic;

        startTime = timeToMin(musicInfo.substr(0, 5));
        endTime = timeToMin(musicInfo.substr(6, 5));

        musicInfo = musicInfo.substr(12);

        name = musicInfo.substr(0, musicInfo.find(","));
        sheetMusic = musicInfo.substr(musicInfo.find(",") + 1);

        eraseSharpInStr(sheetMusic);

        string playData = getPlayData(startTime, endTime, sheetMusic);

        if (playData.find(m) != string::npos) {
            satisfiedMusicInfos.push_back({ i, {playData.length(), name} });
        }
    }

    if (satisfiedMusicInfos.empty() == false) {
        sort(satisfiedMusicInfos.begin(), satisfiedMusicInfos.end(), cmp);
        answer = satisfiedMusicInfos[0].second.second;
    }

    return answer;
}

void service() {

    string m = "CC#BCC#BCC#BCC#B";
    vector<string> ms = { "03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B" };

    cout << solution(m, ms) << endl;
}

방금그곡_END
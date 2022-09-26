#include "��ݱװ�.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

��ݱװ�_BEGIN

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
    
    // �Ǻ����� '#'�� ���� ���� char�� 2���� ���� �����̱� ������ ����ϱ� ��ƴ�.
    // �׷��� '#'�� ���� ���� �ҹ��ڷ� �ٲ㼭 ����ϴ� ����� ����ߴ�.
    // �̷��� �ϸ� ��� ���� char�� 1���� ����� �����ϴ�.

    // �� ���Ǹ��� play time�� ���ؼ� �Ǻ��� ���� play time ���� ���Դ�
    // ���� string ������ ����� m�� ���ԵǾ����� Ȯ���Ѵ�.

    // ������ ������ ������ ����, play time, ���� ���� �����͸� vector�� �����Ѵ�.
    // ������ ���ǿ� �°� �����Ѵ�.

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

��ݱװ�_END
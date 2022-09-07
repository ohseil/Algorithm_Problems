#include "����_����.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

����_����_BEGIN

int timeToSeconds(string time) {
    int hour = stoi(time.substr(0, 2));
    int min = stoi(time.substr(3, 2));
    int seconds = stoi(time.substr(6, 2));
    return (hour * 3600) + (min * 60) + seconds;
}

string secondsToTime(int seconds) {
    string time = "";
    if (seconds / 3600 < 10) time += "0" + to_string(seconds / 3600);
    else time += to_string(seconds / 3600);
    seconds %= 3600;
    if (seconds / 60 < 10) time += ":0" + to_string(seconds / 60);
    else time += ":" + to_string(seconds / 60);
    if (seconds % 60 < 10) time += ":0" + to_string(seconds % 60);
    else time += ":" + to_string(seconds % 60);
    return time;
}

void setWatchTimes(vector<string>& logs, map<int, int>& watchTimes) {

    for (string log : logs) {
        int start = timeToSeconds(log.substr(0, 8));
        int end = timeToSeconds(log.substr(9));
        watchTimes[start]++;
        watchTimes[end]--;
    }
}

void setCountPerTime(vector<int>& times, map<int, int>& watchTimes, int playEndTime) {

    times[0] = watchTimes[0];

    for (int t = 1; t <= playEndTime; t++)
        times[t] += times[t - 1] + watchTimes[t];
}

void findMaxCumulativeTime(vector<int>& times, int playEndTime, int advTime, long long& maxCumulativeTime, string& answer) {

    long long cumulativeTime = 0;

    for (int t = 1; t <= advTime; t++) {
        cumulativeTime += times[t - 1];
    }

    int startTime = 0;
    maxCumulativeTime = cumulativeTime;

    for (int t = advTime + 1; t <= playEndTime; t++) {

        cumulativeTime += times[t - 1];
        cumulativeTime -= times[startTime];

        startTime++;

        if (cumulativeTime > maxCumulativeTime) {
            maxCumulativeTime = cumulativeTime;
            answer = secondsToTime(startTime);
        }
    }
}

string solution(string play_time, string adv_time, vector<string> logs) {
    
    // �� �ʴ����� ��û�� ���� ������ �迭�� �����.
    // �� �������� ���� key: �ð�, value: ��û�� �� ������ map�� watchTimes�� �����Ѵ�.
    // log�� ��� ���۽ð��� ����ð��� Ȯ���ؼ�
    // �ð��� key�� �ϰ� ���� �ð��̸� ��û�� �� ++, ���� �ð��̸� ��û�� �� --.

    // �� ������ �迭�� ����� 0�ʺ��� play_time���� times[t] = times[t-1] + watchTimes[t]�� ����ؼ� �����Ѵ�.
    // �̷��� �� �ʸ��� ������ ��û�� ���� �� �� �ִ�.
    
    // ���������� ���� ��û �ð��� ���Ѵ�.
    // ó�� 0�ʺ��� adv_time������ �� �ʸ����� ��û�� ���� ���Ѵ�.
    // adv_time ���ĺ��ʹ� ������ 1�ʾ� �̵��ϸ鼭 ���� �ð��� �����ϸ鼭 �ִ� �ð��� ã�´�.
    
    // �����ؾ� �� ����,
    // ���� ��û �ð� ������ ���� �ð��� start, ���� �ð��� end��� �Ҷ�,
    // ���� �ð��� ������ �̵��ϸ� start�� end�� ��� 1�ʾ� �����ϴµ�
    // start�� end�� �ٸ��� ó���ؾ� �Ѵ�.
    // ������ �ð��� t��� �ϸ�, start�� �����ϴ� ���� times[t]�� ���ְ�
    // end�� �����ϴ� ���� times[t-1]�� ������� �Ѵ�.
    
    // ���� �ؾ��� �κ��� �����ϱ� ���ؼ��� start�� � ��û ���� ������ �����ϴ� ���ÿ�
    // end�� � ��û ���� ������ �����ϰų� �ϴ�
    // ���� �ð��� ������ �̵������� ��,
    // start�� end�� ���ÿ� ��û ���� �����̳� ���� ������ �����ϴ� ��츦 ������ ���� �ȴ�.

    string answer = "00:00:00";
    long long maxCumulativeTime = 0;

    int playEndTime = timeToSeconds(play_time);
    int advTime = timeToSeconds(adv_time);

    // <�ð�, ��û�� ��>
    map<int, int> watchTimes;

    vector<int> times(playEndTime + 1, 0);

    setWatchTimes(logs, watchTimes);
    setCountPerTime(times, watchTimes, playEndTime);
    findMaxCumulativeTime(times, playEndTime, advTime, maxCumulativeTime, answer);

    return answer;
}

void service() {

    string play_time = "02:03:55";
    string adv_time = "00:14:15";
    vector<string> logs = { "01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30" };
    
    cout << solution(play_time, adv_time, logs) << endl;
}

����_����_END
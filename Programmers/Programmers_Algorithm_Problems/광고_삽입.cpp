#include "광고_삽입.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

광고_삽입_BEGIN

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
    
    // 각 초단위로 시청자 수를 저장할 배열을 만든다.
    // 이 과정에서 먼저 key: 시간, value: 시청자 수 구조의 map인 watchTimes를 구성한다.
    // log의 모든 시작시간과 종료시간을 확인해서
    // 시간을 key로 하고 시작 시간이면 시청자 수 ++, 종료 시간이면 시청자 수 --.

    // 초 단위의 배열을 만들고 0초부터 play_time까지 times[t] = times[t-1] + watchTimes[t]로 계산해서 저장한다.
    // 이러면 각 초마다 순간의 시청자 수를 알 수 있다.
    
    // 마지막으로 누적 시청 시간을 구한다.
    // 처음 0초부터 adv_time까지는 각 초마다의 시청자 수를 더한다.
    // adv_time 이후부터는 범위를 1초씩 이동하면서 누적 시간을 갱신하면서 최대 시간을 찾는다.
    
    // 주의해야 할 점은,
    // 누적 시청 시간 범위의 시작 시간을 start, 종료 시간을 end라고 할때,
    // 누적 시간의 범위를 이동하면 start와 end가 계속 1초씩 증가하는데
    // start와 end를 다르게 처리해야 한다.
    // 도달한 시간을 t라고 하면, start가 도달하는 경우는 times[t]를 빼주고
    // end가 도달하는 경우는 times[t-1]을 더해줘야 한다.
    
    // 주의 해야할 부분을 이해하기 위해서는 start가 어떤 시청 시작 지점에 도달하는 동시에
    // end가 어떤 시청 시작 지점에 도달하거나 하는
    // 누적 시간의 범위를 이동시켰을 때,
    // start와 end가 동시에 시청 시작 지점이나 종료 지점에 도달하는 경우를 생각해 보면 된다.

    string answer = "00:00:00";
    long long maxCumulativeTime = 0;

    int playEndTime = timeToSeconds(play_time);
    int advTime = timeToSeconds(adv_time);

    // <시각, 시청자 수>
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

광고_삽입_END
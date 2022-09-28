#include "셔틀버스.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

셔틀버스_BEGIN

int timeToMin(string time) {
    int hour = stoi(time.substr(0, 2));
    int min = stoi(time.substr(3));
    return hour * 60 + min;
}

void setCrewArrivalTimes(vector<int>& crewArrivalTimes, vector<string>& timetable) {
    
    for (string time : timetable)
        crewArrivalTimes.push_back(timeToMin(time));

    sort(crewArrivalTimes.begin(), crewArrivalTimes.end());
}

string minToTime(int min) {
    string time = "";
    int hour = min / 60;
    min %= 60;
    time += (hour < 10) ? "0" + to_string(hour) : to_string(hour);
    time += ":";
    time += (min < 10) ? "0" + to_string(min) : to_string(min);
    return time;
}

string solution(int n, int t, int m, vector<string> timetable) {
    
    // 기본적인 알고리즘은 이렇다.
    // timetable을 빠른 시간 순으로 오름차순 정렬한다.
    // timetable의 시각을 차례대로 순회하면서 다음 계산을 진행한다.
    // 현재 버스에 태울 수 있으면 승객 수를 증가한다.
    // 태울 수 있는 조건은 (크루 도착 시각 <= 버스 도착 시각) 이다.
    // 승객 수가 꽉 찼다면 다음 버스로 바꾼다.
    // 크루 도착 시각이 버스 도착 시각보다 늦다면,
    // 크루가 탈 수 있는 버스가 올 때까지 버스를 바꾼다.
    // 마지막 버스가 꽉 찼거나 다음 버스가 더 이상 없다면 탐색을 종료한다.

    // 탐색한 정보를 사용해 답을 도출한다.
    // 마지막 버스에 자리가 남았다면 마지막 버스 도착 시각이 가장 늦게 탈 수 있는 시각이다.
    // 또한 마지막 버스가 도착하기 전에 모든 크루가 버스를 타는 경우도 마찬가지다.
    // 마지막 버스에 자리가 꽉찼다면, 마지막으로 탑승한 크루보다 1분 빠르게 도착하면 된다.

    string answer = "";
    
    vector<int> crewArrivalTimes;

    setCrewArrivalTimes(crewArrivalTimes, timetable);

    int curBusArrivalTime = timeToMin("09:00") - t;
    int curPassengerCount = 0;

    int crewIdx = -1;

    for (int i = 0; i < n; i++) {

        curBusArrivalTime += t;
        curPassengerCount = 0;

        for (int j = crewIdx + 1; j < crewArrivalTimes.size(); j++) {

            int crewArrivalTime = crewArrivalTimes[j];

            if (crewArrivalTime <= curBusArrivalTime) {
                curPassengerCount++;
                crewIdx = j;
            }
            else
                break;

            if (curPassengerCount == m)
                break;
        }
    }

    if (curPassengerCount < m)
        answer = minToTime(curBusArrivalTime);
    else
        answer = minToTime(crewArrivalTimes[crewIdx] - 1);

    return answer;
}

void service() {

    int n = 2;
    int t = 10;
    int m = 2;
    vector<string> timetable = { "09:10", "09:09", "08:00" };

    cout << solution(n, t, m, timetable) << endl;
}

셔틀버스_END
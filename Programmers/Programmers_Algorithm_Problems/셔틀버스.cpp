#include "��Ʋ����.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

��Ʋ����_BEGIN

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
    
    // �⺻���� �˰����� �̷���.
    // timetable�� ���� �ð� ������ �������� �����Ѵ�.
    // timetable�� �ð��� ���ʴ�� ��ȸ�ϸ鼭 ���� ����� �����Ѵ�.
    // ���� ������ �¿� �� ������ �°� ���� �����Ѵ�.
    // �¿� �� �ִ� ������ (ũ�� ���� �ð� <= ���� ���� �ð�) �̴�.
    // �°� ���� �� á�ٸ� ���� ������ �ٲ۴�.
    // ũ�� ���� �ð��� ���� ���� �ð����� �ʴٸ�,
    // ũ�簡 Ż �� �ִ� ������ �� ������ ������ �ٲ۴�.
    // ������ ������ �� á�ų� ���� ������ �� �̻� ���ٸ� Ž���� �����Ѵ�.

    // Ž���� ������ ����� ���� �����Ѵ�.
    // ������ ������ �ڸ��� ���Ҵٸ� ������ ���� ���� �ð��� ���� �ʰ� Ż �� �ִ� �ð��̴�.
    // ���� ������ ������ �����ϱ� ���� ��� ũ�簡 ������ Ÿ�� ��쵵 ����������.
    // ������ ������ �ڸ��� ��á�ٸ�, ���������� ž���� ũ�纸�� 1�� ������ �����ϸ� �ȴ�.

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

��Ʋ����_END
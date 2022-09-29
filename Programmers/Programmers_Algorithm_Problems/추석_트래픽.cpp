#include "�߼�_Ʈ����.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

�߼�_Ʈ����_BEGIN

int timeToSecond(string time) {
    int hour = stoi(time.substr(0, 2)) * 1000;
    int min = stoi(time.substr(3, 2)) * 1000;
    int second = stod(time.substr(6)) * 1000;
    return hour * 3600 + min * 60 + second;
}

bool cmp(pair<int, bool> lhs, pair<int, bool> rhs) {
    if (lhs.first < rhs.first)
        return true;
    return false;
}

void setTimeLine(vector<string>& lines, vector<pair<int, bool>>& timeLine) {

    for (string time : lines) {

        int start, end, throughput;

        time = time.substr(time.find(" ") + 1);

        end = timeToSecond(time.substr(0, time.find(" ")));
        
        time = time.substr(time.find(" ") + 1);

        throughput = stod(time.substr(0, time.length() - 1)) * 1000;

        start = end - throughput + 1;

        timeLine.emplace_back(start, true);
        timeLine.emplace_back(end, false);
    }
}

void findMaxThroughputPerSecond(vector<pair<int, bool>>& timeLine, int& answer) {

    int throughput = 0;
    int s = 0, e = 0;

    while (e < timeLine.size()) {

        for (int i = e; i < timeLine.size(); i++) {

            if (timeLine[i].first - timeLine[s].first + 1 > 1000)
                break;

            if (timeLine[i].second == true) {
                throughput++;
                if (throughput > answer)
                    answer = throughput;
            }

            e++;
        }

        if (timeLine[s++].second == false)
            throughput--;
    }
}

int solution(vector<string> lines) {
    
    // �� log���� ���� �ð��� �� �ð��� ����ؼ� ���� �迭�� �����Ѵ�.
    // �� �ð� : S, ó�� �ð� : T, ���� �ð� : S - T + 1

    // ���� �� ��� ���� �ð� �������� ���� ���� �����Ѵ�.
    // �׷� Ÿ�� ������ ���������.
    // ������ ���� 0.000�ʺ��� 1�� ������ 0.001�ʾ� �̵��ϸ鼭 1�� ������ ó������ Ȯ���ϸ� �ȴ�.

    // �� ��, 1�� ������ start�� end�� ���ؼ� �����Ѵ�.
    // 0.001�ʾ� �̵��ϸ� �ð� ���⵵�� �ʹ� ũ��.
    // ������ ��� ������ �����̳� ���� ���� ����̱� ������
    // Ÿ�� ���� �迭�� ���� �Ǿ� �ִ� �ð��� ���ʴ�� Ȯ���ϸ鼭 �����Ѵ�.

    // start�� end�� �ʱ� ���� Ÿ�� ���ο����� ó�� index��.
    // end�� �ϳ��� �̵���Ű�鼭 1�� ������ �Ѿ������ Ž���Ѵ�.
    // 1���� �Ѿ�� start�� �� ĭ �̵���Ų �� �ٽ� end�� 1�� ������ �Ѿ������ Ž���Ѵ�.
    
    // �� ��, end�� �̵� ��ų���� �� �ð��� ������� �ʰ� ���� �ð��� ��쿡�� ó������ +1 ���ش�.
    // �ֳ��ϸ�, � ��û�� ���� ������ start�� �̵����� �ʴ� �� 1���� ������ ���� �����̴�.
    // start ��굵 ���������� ���� �ð��� ������� �ʰ�
    // �̵��� �� �̵� ���� �ð��� ���� �ð��̸� ó������ -1 ���� �� �̵��Ѵ�.

    // Ž���� �����ϸ鼭 ó������ Ȯ���ϸ鼭 �ִ� ó������ ���Ѵ�.

    int answer = 0;
    
    vector<pair<int, bool>> timeLine;

    setTimeLine(lines, timeLine);
    sort(timeLine.begin(), timeLine.end(), cmp);
    findMaxThroughputPerSecond(timeLine, answer);

    return answer;
}

void service() {

    vector<string> lines = { "2016-09-15 00:00:00.000 3s" };

    cout << solution(lines) << endl;
}

�߼�_Ʈ����_END
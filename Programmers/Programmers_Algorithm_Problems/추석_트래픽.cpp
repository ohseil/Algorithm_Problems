#include "추석_트래픽.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

추석_트래픽_BEGIN

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
    
    // 각 log에서 시작 시각과 끝 시각을 계산해서 따로 배열에 저장한다.
    // 끝 시각 : S, 처리 시간 : T, 시작 시각 : S - T + 1

    // 시작 끝 상관 없이 시각 기준으로 오름 차순 정렬한다.
    // 그럼 타임 라인이 만들어진다.
    // 생각해 보면 0.000초부터 1분 범위를 0.001초씩 이동하면서 1분 동안의 처리량을 확인하면 된다.

    // 이 때, 1분 범위의 start와 end를 정해서 진행한다.
    // 0.001초씩 이동하면 시간 복잡도가 너무 크다.
    // 어차피 계산 시점은 시작이나 끝이 나는 경우이기 때문에
    // 타임 라인 배열에 저장 되어 있는 시각을 차례대로 확인하면서 진행한다.

    // start와 end의 초기 값은 타임 라인에서의 처음 index다.
    // end를 하나씩 이동시키면서 1분 범위가 넘어갈때까지 탐색한다.
    // 1분이 넘어가면 start를 한 칸 이동시킨 후 다시 end를 1분 범위가 넘어갈때까지 탐색한다.
    
    // 이 때, end를 이동 시킬때는 끝 시각은 고려하지 않고 시작 시각인 경우에만 처리량을 +1 해준다.
    // 왜냐하면, 어떤 요청이 끝이 났더라도 start가 이동하지 않는 한 1분의 범위에 들어가기 때문이다.
    // start 계산도 마찬가지로 시작 시각은 고려하지 않고
    // 이동할 때 이동 전의 시각이 시작 시각이면 처리량을 -1 해준 후 이동한다.

    // 탐색을 진행하면서 처리량을 확인하면서 최대 처리량을 구한다.

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

추석_트래픽_END
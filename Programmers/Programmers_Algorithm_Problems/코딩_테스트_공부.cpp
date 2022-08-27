#include "코딩_테스트_공부.h"
#include <iostream>
#include <vector>

using namespace std;

코딩_테스트_공부_BEGIN

#define MAX_TIME 300

int solution(int alp, int cop, vector<vector<int>> problems) {
    
    // dp 사용. ( 다익스트라로도 풀이 가능. )
    // 현재 alp, cop 상태에서 3가지 경우의 공부 방법이 있다.
    // alp 1 올리기, cop 1 올리기, 문제 풀기
    // 1. dp[alp+1][cop] = min(dp[alp+1][cop], dp[alp][cop] + 1);
    // 2. dp[alp][cop+1] = min(dp[alp][cop+1], dp[alp][cop] + 1);
    // 3. dp[alp+획득alp][cop+획득cop] = min(dp[alp+획득alp][cop+획득cop], dp[alp][cop] + 문제푸는시간)

    int answer = 300;
    int highestRequiredAlp = 0;
    int highestRequiredCop = 0;

    // alp, cop 1씩 올리는 공부법을 하나의 문제로 추가
    problems.push_back({ 0,0,1,0,1 });
    problems.push_back({ 0,0,0,1,1 });

    for (int i = 0; i < problems.size(); i++) {
        if (problems[i][0] > highestRequiredAlp)
            highestRequiredAlp = problems[i][0];
        if (problems[i][1] > highestRequiredCop)
            highestRequiredCop = problems[i][1];
    }

    if (alp > highestRequiredAlp)
        alp = highestRequiredAlp;
    if (cop > highestRequiredCop)
        cop = highestRequiredCop;

    vector<vector<int>> dp(151, vector<int>(151, MAX_TIME));

    dp[alp][cop] = 0;

    for (int alpi = alp; alpi <= highestRequiredAlp; alpi++) {
        for (int copi = cop; copi <= highestRequiredCop; copi++) {

            for (vector<int> problem : problems) {
                if (alpi >= problem[0] && copi >= problem[1]) {
                    int updateAlpi = (alpi + problem[2] <= highestRequiredAlp) ? (alpi + problem[2]) : highestRequiredAlp;
                    int updateCopi = (copi + problem[3] <= highestRequiredCop) ? (copi + problem[3]) : highestRequiredCop;
                    dp[updateAlpi][updateCopi] = min(dp[updateAlpi][updateCopi], dp[alpi][copi] + problem[4]);
                }
            }
        }
    }

    answer = dp[highestRequiredAlp][highestRequiredCop];

    return answer;
}

void service() {

    int alp = 0;
    int cop = 0;
    vector<vector<int>> ps = { {0,0,2,1,2},{4,5,3,1,2},{4,11,4,0,2},{10,4,0,4,2} };

    cout << solution(alp, cop, ps) << endl;

}

코딩_테스트_공부_END
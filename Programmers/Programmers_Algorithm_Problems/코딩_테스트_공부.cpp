#include "�ڵ�_�׽�Ʈ_����.h"
#include <iostream>
#include <vector>

using namespace std;

�ڵ�_�׽�Ʈ_����_BEGIN

#define MAX_TIME 300

int solution(int alp, int cop, vector<vector<int>> problems) {
    
    // dp ���. ( ���ͽ�Ʈ��ε� Ǯ�� ����. )
    // ���� alp, cop ���¿��� 3���� ����� ���� ����� �ִ�.
    // alp 1 �ø���, cop 1 �ø���, ���� Ǯ��
    // 1. dp[alp+1][cop] = min(dp[alp+1][cop], dp[alp][cop] + 1);
    // 2. dp[alp][cop+1] = min(dp[alp][cop+1], dp[alp][cop] + 1);
    // 3. dp[alp+ȹ��alp][cop+ȹ��cop] = min(dp[alp+ȹ��alp][cop+ȹ��cop], dp[alp][cop] + ����Ǫ�½ð�)

    int answer = 300;
    int highestRequiredAlp = 0;
    int highestRequiredCop = 0;

    // alp, cop 1�� �ø��� ���ι��� �ϳ��� ������ �߰�
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

�ڵ�_�׽�Ʈ_����_END
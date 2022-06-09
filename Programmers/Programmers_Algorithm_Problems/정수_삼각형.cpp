#include "����_�ﰢ��.h"

int ����_�ﰢ��::solution(vector<vector<int>> triangle) {
    
    // dp ���

    int answer = 0;
    
    vector<vector<int>> dp;

    for (int i = 0; i < triangle.size(); i++) {
        dp.push_back(vector<int>(triangle[i].size(), 0));
    }

    dp[0][0] = triangle[0][0];

    for (int depth = 1; depth < triangle.size(); depth++) {

        vector<int> line = dp[depth - 1];

        int len = dp[depth].size();

        // ���� �հ� ���� ���� ��ΰ� �Ѱ�.
        dp[depth][0] = line[0] + triangle[depth][0];
        dp[depth][len - 1] = line[len - 2] + triangle[depth][len - 1];

        // ������ ��� Ȯ��
        // ���� ������ ��� �� ���� index�� index - 1 ��ġ�� ���κ��� 2���� ��� ����
        for (int i = 1; i < len - 1; i++) {

            dp[depth][i] = max(line[i - 1], line[i]) + triangle[depth][i];
        }
    }

    for (int sum : dp[triangle.size() - 1])
        answer = max(answer, sum);

    return answer;
}

void ����_�ﰢ��::service() {

    vector<vector<int>> tr = { {7},{3,8},{8,1,0},{2,7,4,4},{4,5,2,6,5} };
    cout << solution(tr) << endl;
}
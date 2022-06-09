#include "정수_삼각형.h"

int 정수_삼각형::solution(vector<vector<int>> triangle) {
    
    // dp 사용

    int answer = 0;
    
    vector<vector<int>> dp;

    for (int i = 0; i < triangle.size(); i++) {
        dp.push_back(vector<int>(triangle[i].size(), 0));
    }

    dp[0][0] = triangle[0][0];

    for (int depth = 1; depth < triangle.size(); depth++) {

        vector<int> line = dp[depth - 1];

        int len = dp[depth].size();

        // 가장 앞과 뒤의 노드는 경로가 한개.
        dp[depth][0] = line[0] + triangle[depth][0];
        dp[depth][len - 1] = line[len - 2] + triangle[depth][len - 1];

        // 나머지 노드 확인
        // 위의 높이의 노드 중 같은 index와 index - 1 위치의 노드로부터 2가지 경로 가능
        for (int i = 1; i < len - 1; i++) {

            dp[depth][i] = max(line[i - 1], line[i]) + triangle[depth][i];
        }
    }

    for (int sum : dp[triangle.size() - 1])
        answer = max(answer, sum);

    return answer;
}

void 정수_삼각형::service() {

    vector<vector<int>> tr = { {7},{3,8},{8,1,0},{2,7,4,4},{4,5,2,6,5} };
    cout << solution(tr) << endl;
}
#include "최적의_행렬_곱셈.h"
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

최적의_행렬_곱셈_BEGIN

int solution(vector<vector<int>> matrix_sizes) {
    
    // 이 문제를 푸는 잘 알려진 알고리즘이 있다.
    // 연쇄 행렬 곱셈 알고리즘이다.
    // dp를 사용한 방법이다.

    // 과정은 이렇다.
    // 우선 n개의 matrix의 곱셈의 최소를 구하는 과정을
    // (1개의 matrix 곱) * (n-1개의 matrix 곱), (2개의 matrix 곱) * (n-2개의 matrix 곱), ..., (n-1개의 matrix 곱) * (1개의 matrix 곱)
    // 이 경우 중 가장 최소 값을 구하는 것이라고 볼 수 있다.
    // 그러면 여기서 떠오르는 생각은 n-1개의 matrix 곱도 여러 가지 경우의 수가 있는데 이건 어떻게 구해야 하는가 이다.
    // 이 것도 마찬가지로 n-1개의 matrix의 곱셈의 최소를 구하는 과정을 위와 같은 방법으로 구한다.

    // dp[i][j] = i번째 matrix부터 j번째 matrix까지의 곱의 최소 값으로 정한다.
    // dp[i][i]는 1개의 matrix의 곱을 의미한다. 1개의 matrix 곱의 최소 값은 당연히 0이다.
    // 1개의 범위를 구했으니 2개의 범위부터 n개의 범위까지 차례대로 dp 값을 구하면, 답은 dp[0][n-1]이 된다.

    int answer = 0;
    
    int len = matrix_sizes.size();

    vector<vector<int>> dp(len, vector<int>(len, INT_MAX));

    for (int i = 0; i < len; i++)
        dp[i][i] = 0;

    for (int i = 1; i < len; i++) {

        for (int j = 0; j < len - i; j++) {

            // j ~ j + i matrix 곱의 최소 값 구하기
            for (int k = 0; k < i; k++) {

                int value = dp[j][j + k] + dp[j + k + 1][j + i] + matrix_sizes[j][0] * matrix_sizes[j + k][1] * matrix_sizes[j + i][1];
                dp[j][j + i] = min(dp[j][j + i], value);
            }
        }
    }

    answer = dp[0][len - 1];

    return answer;
}

void service() {

    vector<vector<int>> v = { {5,3},{3,10},{10,6} };

    cout << solution(v) << endl;
}

최적의_행렬_곱셈_END
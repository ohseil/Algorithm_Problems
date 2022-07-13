#include "3xn_타일링.h"
#include <iostream>

using namespace std;

_3xN_타일링_BEGIN_

#define DIV_NUM 1000000007

int solution(int n) {
    
    // 가로의 길이가 홀수인 경우에는 어떤 방법으로도 채울 수 없다.
    // 가로의 길이가 짝수인 경우에만 규칙을 찾아서 dp 사용.

    if (n % 2 != 0)
        return 0;
    
    int answer = 0;

    int dp[2501];
    dp[0] = 1;
    dp[1] = 3;

    for (int i = 2; i <= n / 2; i++) {
        
        dp[i] = ((dp[i - 1] + dp[i - 1]) % DIV_NUM + dp[i - 1]) % DIV_NUM;

        for (int j = 2; j <= i; j++)
            dp[i] = (dp[i] + (dp[i - j] * 2) % DIV_NUM) % DIV_NUM;
    }

    answer = dp[n / 2];

    return answer;
}

void service() {

    int n = 4;
    cout << solution(n) << endl;
}

_3xN_타일링_END_
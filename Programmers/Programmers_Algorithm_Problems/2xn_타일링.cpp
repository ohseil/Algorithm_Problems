#include "2xn_타일링.h"
#include <iostream>

using namespace std;

_2xN_타일링_BEGIN_

#define DIV_NUM 1000000007

int solution(int n) {

    int answer = 0;
    
    int dp[60001];

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % DIV_NUM;
    }

    answer = dp[n];

    return answer;
}

void service() {

    int n = 4;
    cout << solution(n) << endl;

}

_2xN_타일링_END_
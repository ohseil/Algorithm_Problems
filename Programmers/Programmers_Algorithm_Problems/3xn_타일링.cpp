#include "3xn_Ÿ�ϸ�.h"
#include <iostream>

using namespace std;

_3xN_Ÿ�ϸ�_BEGIN_

#define DIV_NUM 1000000007

int solution(int n) {
    
    // ������ ���̰� Ȧ���� ��쿡�� � ������ε� ä�� �� ����.
    // ������ ���̰� ¦���� ��쿡�� ��Ģ�� ã�Ƽ� dp ���.

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

_3xN_Ÿ�ϸ�_END_
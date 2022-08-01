#include "¸Ö¸®_¶Ù±â.h"
#include <iostream>
#include <vector>

using namespace std;

¸Ö¸®_¶Ù±â_BEGIN

#define DIV_NUM 1234567

long long solution(int n) {

    long long answer = 0;

    vector<long long> dp(2001, 0);
    dp[1] = dp[0] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % DIV_NUM;

    answer = dp[n];

    return answer;
}

void service() {

    int n = 4;
    cout << solution(n) << endl;
}

¸Ö¸®_¶Ù±â_END
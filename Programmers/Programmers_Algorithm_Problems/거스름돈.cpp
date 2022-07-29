#include "거스름돈.h"
#include <iostream>
#include <vector>

using namespace std;

거스름돈_BEGIN

int solution(int n, vector<int> money) {
    
    // dp를 사용했다.
    // dp[n] = n원을 낼 수 있는 경우의 가지 수
    // 각 동전 마다 dp 배열을 채운다.
    // 동전의 금액이 x라고 한다면,
    // dp[n] += dp[n - x]이다.
    // 동전마다 각 금액을 동전 x원으로 채우는 경우를 센다.

    // dp[n]마다 모든 금액의 동전을 채우는 방법으로 세면 답이 맞지 않는다.
    // 이유는 예를 들어, 동전 2원 4원짜리가 있을 때
    // dp[n] 마다 +dp[n-2]+dp[n-4] 를 하게되면
    // dp[n-2-4]에서 4원 2원을 채우는 경우와
    // dp[n-4-2]에서 2원 4원을 채우는 경우가 겹친다.
    // 순서에 상관이 없이 동전의 개수로만 판단해야 하기 때문이다.

    // 따라서 결론은, 일반적인 dp 계산과 조금 다른 방법으로 계산해야 한다.
    // 동전 하나로 dp를 모두 계산하고
    // 다른 동전으로 다시 dp를 모두 계산하는 방법으로 계산해야 한다.

    int answer = 0;
    
    vector<int> dp(n + 1, 0);

    dp[0] = 1;

	for (int m : money) {

		for (int cost = 1; cost <= n; cost++) {

			if (cost < m)
				continue;

			dp[cost] += dp[cost - m];
		}
	}
    
    answer = dp[n];

    return answer;
}

void service() {

    int n = 5;
    vector<int> m = { 1,2,5 };
    cout << solution(n, m) << endl;
}

거스름돈_END
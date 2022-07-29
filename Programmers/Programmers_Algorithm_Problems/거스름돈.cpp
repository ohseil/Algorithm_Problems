#include "�Ž�����.h"
#include <iostream>
#include <vector>

using namespace std;

�Ž�����_BEGIN

int solution(int n, vector<int> money) {
    
    // dp�� ����ߴ�.
    // dp[n] = n���� �� �� �ִ� ����� ���� ��
    // �� ���� ���� dp �迭�� ä���.
    // ������ �ݾ��� x��� �Ѵٸ�,
    // dp[n] += dp[n - x]�̴�.
    // �������� �� �ݾ��� ���� x������ ä��� ��츦 ����.

    // dp[n]���� ��� �ݾ��� ������ ä��� ������� ���� ���� ���� �ʴ´�.
    // ������ ���� ���, ���� 2�� 4��¥���� ���� ��
    // dp[n] ���� +dp[n-2]+dp[n-4] �� �ϰԵǸ�
    // dp[n-2-4]���� 4�� 2���� ä��� ����
    // dp[n-4-2]���� 2�� 4���� ä��� ��찡 ��ģ��.
    // ������ ����� ���� ������ �����θ� �Ǵ��ؾ� �ϱ� �����̴�.

    // ���� �����, �Ϲ����� dp ���� ���� �ٸ� ������� ����ؾ� �Ѵ�.
    // ���� �ϳ��� dp�� ��� ����ϰ�
    // �ٸ� �������� �ٽ� dp�� ��� ����ϴ� ������� ����ؾ� �Ѵ�.

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

�Ž�����_END
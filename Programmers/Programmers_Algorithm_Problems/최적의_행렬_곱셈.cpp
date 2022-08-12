#include "������_���_����.h"
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

������_���_����_BEGIN

int solution(vector<vector<int>> matrix_sizes) {
    
    // �� ������ Ǫ�� �� �˷��� �˰����� �ִ�.
    // ���� ��� ���� �˰����̴�.
    // dp�� ����� ����̴�.

    // ������ �̷���.
    // �켱 n���� matrix�� ������ �ּҸ� ���ϴ� ������
    // (1���� matrix ��) * (n-1���� matrix ��), (2���� matrix ��) * (n-2���� matrix ��), ..., (n-1���� matrix ��) * (1���� matrix ��)
    // �� ��� �� ���� �ּ� ���� ���ϴ� ���̶�� �� �� �ִ�.
    // �׷��� ���⼭ �������� ������ n-1���� matrix ���� ���� ���� ����� ���� �ִµ� �̰� ��� ���ؾ� �ϴ°� �̴�.
    // �� �͵� ���������� n-1���� matrix�� ������ �ּҸ� ���ϴ� ������ ���� ���� ������� ���Ѵ�.

    // dp[i][j] = i��° matrix���� j��° matrix������ ���� �ּ� ������ ���Ѵ�.
    // dp[i][i]�� 1���� matrix�� ���� �ǹ��Ѵ�. 1���� matrix ���� �ּ� ���� �翬�� 0�̴�.
    // 1���� ������ �������� 2���� �������� n���� �������� ���ʴ�� dp ���� ���ϸ�, ���� dp[0][n-1]�� �ȴ�.

    int answer = 0;
    
    int len = matrix_sizes.size();

    vector<vector<int>> dp(len, vector<int>(len, INT_MAX));

    for (int i = 0; i < len; i++)
        dp[i][i] = 0;

    for (int i = 1; i < len; i++) {

        for (int j = 0; j < len - i; j++) {

            // j ~ j + i matrix ���� �ּ� �� ���ϱ�
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

������_���_����_END
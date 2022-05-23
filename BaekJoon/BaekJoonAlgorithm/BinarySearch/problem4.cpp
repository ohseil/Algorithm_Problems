#include "problem4.h"

namespace problem4 {

	// len ���̷� ������ �� ���� �� �ִ� �� ���� ���� ���ϴ� �Լ�
	long long lineNum(int len, vector<int> lines) {

		long long num = 0;

		for (int line : lines)
			num += (line / len);

		return num;
	}

	int solution(int n, vector<int> lines) {

		// �̺�Ž�� ����. ������ ���̴� �ִ� 2^31 - 1

		int answer;
		long long left, mid, right;

		left = 0;
		right = 2147483647; // 2^31 - 1

		while (left <= right) {

			mid = (left + right) / 2;

			if (lineNum(mid, lines) < n) {
				right = mid - 1;
			}
			else {
				answer = mid;
				left = mid + 1;
			}
		}

		return answer;
	}

	void execute() {

		int n, k;
		vector<int> lines;

		cin >> k >> n;

		lines.assign(k, 0);
		for (int i = 0; i < k; i++)
			cin >> lines[i];

		cout << solution(n, lines);
	}
}
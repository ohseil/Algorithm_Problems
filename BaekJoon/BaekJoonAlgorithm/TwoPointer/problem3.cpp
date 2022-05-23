#include "problem3.h"

namespace problem3 {

	vector<int> p;
	vector<int> check;

	void makePrimes(int n) {

		// �����佺�׳׽��� ü ������ �̿��ؼ� �Ҽ� ���ϱ�.

		check.assign(n + 1, true);

		for (int i = 2; i * i <= n; i++) {

			if (!check[i]) continue;

			for (int j = i * i; j <= n; j += i)
				check[j] = false;
		}

		for (int i = 2; i <= n; i++)
			if (check[i]) p.push_back(i);
	}

	int solution(int n) {

		// �̸� ���س��� �Ҽ� �迭�� �̿��ؼ�
		// �������� �˰��� ����.

		int answer = 0;
		int size = p.size();
		int s = 0, e = 0, sum = 0;

		while (true) {

			if (sum >= n) sum -= p[s++];
			else if (e == size) break;
			else sum += p[e++];

			if (sum == n)
				answer++;
		}

		return answer;
	}

	void execute() {

		int n;
		cin >> n;

		makePrimes(n);

		cout << solution(n) << endl;
	}
}
#include "problem3.h"

namespace problem3 {

	vector<int> p;
	vector<int> check;

	void makePrimes(int n) {

		// 에라토스테네스의 체 공식을 이용해서 소수 구하기.

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

		// 미리 구해놓은 소수 배열을 이용해서
		// 투포인터 알고리즘 실행.

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
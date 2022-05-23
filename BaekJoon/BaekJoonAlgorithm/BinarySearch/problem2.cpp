#include "problem2.h"

namespace problem2 {

	// 잘린 나무의 합을 구하는 함수
	long long sumTreeHeight(int sliceHeight, vector<int> trees) {
		
		long long sum = 0;

		for (int tree : trees)
			sum += (tree - sliceHeight > 0 ? tree - sliceHeight : 0);

		return sum;
	}

	void solution(int n, int m, vector<int> trees) {

		// 0 ~ 10억까지 이분탐색.

		int left, mid, right, answer = 0;

		left = 0;
		right = 1000000000;

		while (left <= right) {

			mid = (left + right) / 2;

			if (sumTreeHeight(mid, trees) < m) {
				right = mid - 1;
			}
			else {
				answer = mid;
				left = mid + 1;
			}
		}

		cout << answer << endl;
	}

	void execute() {

		// n : 나무 수
		// m : 가져가려는 나무 길이
		// 각 나무의 최대 높이는 10억.
		int n, m;

		vector<int> trees;

		cin >> n >> m;

		trees.assign(n, 0);
		for (int i = 0; i < n; i++)
			cin >> trees[i];

		solution(n, m, trees);
	}
}
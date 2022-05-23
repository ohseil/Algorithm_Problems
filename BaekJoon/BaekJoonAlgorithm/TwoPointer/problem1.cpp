#include "problem1.h"

namespace problem1 {

	int solution(int m, vector<int> nums) {

		int answer = 0;
		int s = 0, e = 0, sum = 0;

		while (true) {

			if (sum >= m) sum -= nums[s++];
			else if (e == nums.size()) break;
			else sum += nums[e++];
			if (sum == m) answer++;
		}

		return answer;
	}

	void execute() {

		int n, m;
		vector<int> nums;

		/*
		cin >> n >> m;
		nums.assign(n, 0);

		for (int i = 0; i < n; i++)
			cin >> nums[i];
			*/

		n = 10, m = 5;
		nums.assign(n, 0);
		nums[0] = 1;
		nums[1] = 2;
		nums[2] = 3;
		nums[3] = 4;
		nums[4] = 2;
		nums[5] = 5;
		nums[6] = 3;
		nums[7] = 1;
		nums[8] = 1;
		nums[9] = 2;

		cout << solution(m, nums);
	}
}
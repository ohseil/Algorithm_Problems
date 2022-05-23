#include "problem2.h"

namespace problem2 {

	int solution(int m, vector<int> nums) {

		int answer = 100001;

		int s = 0, e = 0, sum = 0;

		while (true) {

			bool moved = false;

			if (sum >= m) sum -= nums[s++];
			else if (e == nums.size()) break;
			else sum += nums[e++];

			if (sum >= m && e - s < answer)
				answer = e - s;
		}

		if (answer > 100000)
			answer = 0;

		return answer;
	}

	void execute() {

		int n, m;
		vector<int> nums;

		cin >> n >> m;
		nums.assign(n, 0);

		for (int i = 0; i < n; i++)
			cin >> nums[i];

		cout << solution(m, nums);
	}
}
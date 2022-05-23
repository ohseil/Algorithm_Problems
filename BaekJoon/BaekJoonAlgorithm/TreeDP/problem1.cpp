#include "problem1.h"

namespace problem1 {

	unordered_map<int, vector<int>> treeMap;
	int dp[1000001][2], visited[1000001] = { 0, };

	void cal(int node) {

		visited[node] = 1;

		for (auto child : treeMap[node]) {

			if (visited[child] == 1)
				continue;

			cal(child);

			dp[node][0] += dp[child][1];
			dp[node][1] += min(dp[child][0], dp[child][1]);
		}

		dp[node][1] += 1;
	}

	int solution(int n, vector<vector<int>> relations) {

		// 1. tree map 생성.
		// 2. dp 실행.

		int answer = 0;

		for (auto relation : relations) {
			treeMap[relation[0]].push_back(relation[1]);
			treeMap[relation[1]].push_back(relation[0]);
		}

		cal(1);

		return dp[1][0] < dp[1][1] ? dp[1][0] : dp[1][1];
	}

	void execute() {

		int n;
		vector<vector<int>> v;
		
		/*cin >> n;
		for (int i = 0; i < n; i++) {
			vector<int> temp(2, 0);
			cin >> temp[0] >> temp[1];
			v.push_back(temp);
		}*/

		n = 8;

		vector<int> vv(2, 0);
		vv[0] = 1; vv[1] = 2;
		v.push_back(vv);
		vv[0] = 1; vv[1] = 3;
		v.push_back(vv);
		vv[0] = 1; vv[1] = 4;
		v.push_back(vv);
		vv[0] = 2; vv[1] = 5;
		v.push_back(vv);
		vv[0] = 2; vv[1] = 6;
		v.push_back(vv);
		vv[0] = 4; vv[1] = 8;
		v.push_back(vv);
		vv[0] = 4; vv[1] = 8;
		v.push_back(vv);

		cout << solution(n, v) << endl;

	}
}
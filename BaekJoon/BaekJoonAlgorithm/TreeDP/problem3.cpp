#include "problem3.h"

namespace problem3 {

	unordered_map<int, vector<int>> treeMap;
	vector<int> w; // 가중치 데이터
	int dp[10001][2], visited[10001] = { 0, };

	void cal(int node) {

		visited[node] = 1;

		for (auto child : treeMap[node]) {

			if (visited[child] == 1)
				continue;

			cal(child);

			dp[node][0] += max(dp[child][0], dp[child][1]);
			dp[node][1] += dp[child][0];
		}

		dp[node][1] += w[node];
	}

	int solution(int n, vector<vector<int>> links) {

		// 1. tree map 생성.
		// 2. dp process 실행.

		for (auto link : links) {
			treeMap[link[0]].push_back(link[1]);
			treeMap[link[1]].push_back(link[0]);
		}

		cal(1);

		return dp[1][0] > dp[1][1] ? dp[1][0] : dp[1][1];
	}

	void execute() {

		int n;
		vector<vector<int>> links;

		cin >> n;
		w.assign(n + 1, 0);
		for (int i = 1; i <= n; i++)
			cin >> w[i];
		for (int i = 0; i < n - 1; i++) {
			vector<int> v(2, 0);
			cin >> v[0] >> v[1];
			links.push_back(v);
		}

		/*n = 7;
		w.assign(8, 0);
		w[1] = 1000;
		w[2] = 3000;
		w[3] = 4000;
		w[4] = 1000;
		w[5] = 2000;
		w[6] = 2000;
		w[7] = 7000;

		vector<int> vv(2, 0);
		vv[0] = 1; vv[1] = 2;
		links.push_back(vv);
		vv[0] = 2; vv[1] = 3;
		links.push_back(vv);
		vv[0] = 4; vv[1] = 3;
		links.push_back(vv);
		vv[0] = 4; vv[1] = 5;
		links.push_back(vv);
		vv[0] = 6; vv[1] = 2;
		links.push_back(vv);
		vv[0] = 6; vv[1] = 7;
		links.push_back(vv);*/

		cout << solution(n, links) << endl;
			
	}
}
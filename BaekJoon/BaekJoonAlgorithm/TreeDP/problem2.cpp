#include "problem2.h"

namespace problem2 {

	unordered_map<int, vector<int>> treeMap;
	// 경로의 노드정보를 저장하는 map.
	unordered_map<int, unordered_map<int, vector<int>>> lists;
	int dp[10001][2], visited[10001] = { 0, };

	void cal(int node, vector<int> weights) {

		visited[node] = 1;

		for (auto child : treeMap[node]) {

			if (visited[child] == 1)
				continue;

			cal(child, weights);

			vector<int> childList;
			if (dp[child][0] < dp[child][1]) {
				dp[node][0] += dp[child][1];
				childList = lists[child][1];
			}
			else {
				dp[node][0] += dp[child][0];
				childList = lists[child][0];
			}

			for (auto cl : childList)
				lists[node][0].push_back(cl);

			dp[node][1] += dp[child][0];
			for (auto cl : lists[child][0])
				lists[node][1].push_back(cl);
		}

		dp[node][1] += weights[node];
		lists[node][1].push_back(node);
	}

	void solution(int n, vector<int> weights, vector<vector<int>> links) {

		// 1. tree map 생성.
		// 2. dp process 실행.

		for (auto link : links) {
			treeMap[link[0]].push_back(link[1]);
			treeMap[link[1]].push_back(link[0]);
		}

		cal(1, weights);

		vector<int> results;

		if (dp[1][0] > dp[1][1]) {
			cout << dp[1][0] << endl;
			results = lists[1][0];
		}
		else {
			cout << dp[1][1] << endl;
			results = lists[1][1];
		}

		sort(results.begin(), results.end());
		for (auto node : results)
			cout << node << " ";
	}

	void execute() {

		int n;
		vector<int> weights;
		vector<vector<int>> links;

		/*cin >> n;

		weights.assign(n + 1, 0);

		for (int i = 1; i <= n; i++)
			cin >> weights[i];

		for (int i = 0; i < n; i++) {
			vector<int> v(2, 0);
			cin >> v[0] >> v[1];
			links.push_back(v);
		}*/

		n = 7;
		weights.assign(8, 0);
		weights[1] = 10;
		weights[2] = 30;
		weights[3] = 40;
		weights[4] = 10;
		weights[5] = 20;
		weights[6] = 20;
		weights[7] = 70;

		vector<int> v(2, 0);
		v[0] = 1; v[1] = 2;
		links.push_back(v);
		v[0] = 2; v[1] = 3;
		links.push_back(v);
		v[0] = 4; v[1] = 3;
		links.push_back(v);
		v[0] = 4; v[1] = 5;
		links.push_back(v);
		v[0] = 6; v[1] = 2;
		links.push_back(v);
		v[0] = 6; v[1] = 7;
		links.push_back(v);

		solution(n, weights, links);
	}
}
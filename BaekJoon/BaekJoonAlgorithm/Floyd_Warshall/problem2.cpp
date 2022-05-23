#include "problem2.h"

namespace problem2 {

#define inf 10000

	bool comp(pair<int, int> lhs, pair<int, int> rhs) {
		if (lhs.second < rhs.second)
			return true;
		else if (lhs.second == rhs.second)
			if (lhs.first < rhs.first)
				return true;
		return false;
	}

	void execute() {

		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int n, m;

		cin >> n >> m;

		vector<vector<int>> links(n + 1, vector<int>(n + 1, inf));

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			links[a][b] = 1;
			links[b][a] = 1;
		}

		for (int i = 1; i <= n; i++)
			links[i][i] = 0;

		for (int m = 1; m <= n; m++) {
			for (int s = 1; s <= n; s++) {
				for (int e = 1; e <= n; e++) {
					if (links[s][e] > links[s][m] + links[m][e]) {
						links[s][e] = links[s][m] + links[m][e];
					}
				}
			}
		}

		vector<pair<int, int>> sums;

		for (int i = 1; i <= n; i++) {
			int sum = 0;
			for (int j = 1; j <= n; j++)
				sum += links[i][j];
			sums.push_back(make_pair<int, int>((int)i, (int)sum));
		}

		sort(sums.begin(), sums.end(), comp);

		cout << sums[0].first << endl;
	}
}
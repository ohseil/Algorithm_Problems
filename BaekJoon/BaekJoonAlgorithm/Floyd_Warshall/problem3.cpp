#include "problem3.h"

namespace problem3 {

#define inf 10000001

	void execute() {

		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int n, m;

		cin >> n >> m;

		vector<vector<int>> links(n + 1, vector<int>(n + 1, inf));

		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			if (links[a][b] > c)
				links[a][b] = c;
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

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (links[i][j] == inf)
					cout << 0 << " ";
				else
					cout << links[i][j] << " ";
			}
			cout << endl;
		}
	}
}
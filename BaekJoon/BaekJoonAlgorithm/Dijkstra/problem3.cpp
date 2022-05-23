#include "problem3.h"

namespace problem3 {

#define inf 2000000000

	int dm[4] = { -1, 1, 0, 0 };
	int dn[4] = { 0, 0, -1, 1 };

	// 위치 class
	class pos {
	public:
		int m;
		int n;

		pos(int m, int n) : m(m), n(n)
		{
		}
	};

	bool isBlock(int N, int M, pos p) {
		return 0 > p.m || p.m >= M || 0 > p.n || p.n >= N;
	}

	struct comp {

		bool operator()(pair<int, pos>& lhs, pair<int, pos>& rhs) {
			if (lhs.first > rhs.first) return true;
			return false;
		}
	};

	void solution(int N, int M, vector<vector<int>> maze) {

		vector<vector<int>> cost(M, vector<int>(N, inf));
		vector<vector<int>> visited(M, vector<int>(N, 0));

		cost[0][0] = maze[0][0];

		priority_queue<pair<int, pos>, vector<pair<int, pos>>, comp> pq;
		pq.push(make_pair<int, pos>((int)cost[0][0], pos(0, 0)));

		while (pq.empty() == false) {

			pos curPos = pq.top().second;
			int curCost = pq.top().first;
			pq.pop();

			if (visited[curPos.m][curPos.n] == 1)
				continue;

			// 현재 위치에서 4방향으로 움직일 수 있기 때문에
			// 4가지 경우를 고려한다.
			for (int i = 0; i < 4; i++) {

				pos nextPos(curPos.m + dm[i], curPos.n + dn[i]);

				if (isBlock(N, M, nextPos) || visited[nextPos.m][nextPos.n] == 1)
					continue;

				if (curCost + maze[nextPos.m][nextPos.n] < cost[nextPos.m][nextPos.n]) {
					cost[nextPos.m][nextPos.n] = curCost + maze[nextPos.m][nextPos.n];
					pq.push(make_pair<int, pos>((int)cost[nextPos.m][nextPos.n], (pos)nextPos));
				}
			}

		}

		cout << cost[M - 1][N - 1] << endl;
	}

	void execute() {

		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int N, M;
		
		cin >> N >> M;

		vector<vector<int>> maze(M, vector<int>(N, 0));

		for (int m = 0; m < M; m++) {
			string row;
			cin >> row;
			for (int n = 0; n < N; n++)
				maze[m][n] = row[n] - '0';
		}

		solution(N, M, maze);
	}
}
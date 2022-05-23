#include "problem1.h"

namespace problem1 {

#define inf 2000000000

	void solution(int N, int M, int W, vector<vector<int>> roads, vector<vector<int>> warmholes) {

		// 지점 1번 ~ N번
		// 출발점은 아무 지점으로 정해도 상관 없으므로 쉽게 1번으로 한다.

		string answer = "NO";

		vector<int> dist(N + 1, inf);
		dist[1] = 0;

		// N번 모든 간선을 확인한다.
		// 도로와 연결된 지점 중 출발 지점이 inf가 아닐 경우만 갱신.
		for (int i = 0; i < N; i++) {

			bool isUpdated = false;

			// 도로의 경우 양방향이므로 두가지 경우 고려.
			for (auto road : roads) {

				int a = road[0];
				int b = road[1];
				int time = road[2];

				if (dist[a] + time < dist[b]) {
					dist[b] = dist[a] + time;
					isUpdated = true;
				}

				if (dist[b] + time < dist[a]) {
					dist[a] = dist[b] + time;
					isUpdated = true;
				}
			}

			// 웜홀의 경우 한방향이므로 한가지만 고려.
			for (auto hole : warmholes) {

				int s = hole[0];
				int e = hole[1];
				int time = -hole[2];

				if (dist[s] + time < dist[e]) {
					dist[e] = dist[s] + time;
					isUpdated = true;
				}
			}

			if (i == N - 1 && isUpdated == true)
				answer = "YES";
		}

		cout << answer << endl;
	}

	void execute() {

		int TC;

		cin >> TC;

		for (int i = 0; i < TC; i++) {

			int N, M, W;

			cin >> N >> M >> W;

			vector<vector<int>> roads(M, vector<int>(3, 0));
			vector<vector<int>> warmholes(W, vector<int>(3, 0));

			for (int j = 0; j < M; j++)
				cin >> roads[j][0] >> roads[j][1] >> roads[j][2];
			for (int j = 0; j < W; j++)
				cin >> warmholes[j][0] >> warmholes[j][1] >> warmholes[j][2];

			solution(N, M, W, roads, warmholes);
		}


	}
}
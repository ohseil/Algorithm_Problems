#include "problem2.h"

namespace problem2 {

#define inf 200000000

	void solution(int N, int M, vector<vector<int>> buses) {

		// dist 배열의 자료형이 long long인 이유는
		// 벨만포드 알고리즘의 경우,
		// 노드 수 만큼 루프를 돌면서 각 루프마다 모든 엣지를 갱신하는데
		// cycle이 있을 최대 경우 노드 수 x 엣지 수 만큼 갱신을 한다.
		// 예를 들면, a -> b -> c -> a 이런 그래프의 경우이다.
		// 이 문제에서 노드의 수가 최대 500, 엣지의 개수가 최대 6000, 가중치 값이 최소 -10000 이다.
		// 그럼 이 경우에 업데이트를 계속 하면 500 * 6000 * (-10000)의 값 (-300억)으로 업데이트 될것이다.
		// 이 경우에 int 범위를 넘어서게 된다.

		vector<long long> dist(N + 1, inf);
		dist[1] = 0;

		bool isCycle = false;

		for (int i = 0; i < N; i++) {

			for (auto bus : buses) {

				int s = bus[0];
				int e = bus[1];
				int time = bus[2];

				if (dist[s] == inf)
					continue;

				if (dist[s] + time < dist[e]) {
					dist[e] = dist[s] + time;

					if (i == N - 1)
						isCycle = true;
				}
			}
		}

		if (isCycle == true) {
			cout << -1 << endl;
		}
		else {

			for (int i = 2; i <= N; i++) {

				if (dist[i] == inf)
					cout << -1 << endl;
				else
					cout << dist[i] << endl;
			}
		}
	}


	void execute() {

		int N, M;

		cin >> N >> M;

		vector<vector<int>> buses(M, vector<int>(3, 0));

		for (int i = 0; i < M; i++)
			cin >> buses[i][0] >> buses[i][1] >> buses[i][2];

		solution(N, M, buses);

	}
}
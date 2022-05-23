#include "problem3.h"

namespace problem3 {

#define inf 2000000000

	void solution(int N, int M, int start, int end, vector<vector<int>> transports, vector<int> moneys) {

		vector<long long> dist(N, -inf);
		dist[start] = moneys[start];

		// 임의의 도시에 도착하면 무조건 돈을 벌 수 있으므로, 
		// a -> b 의 비용을
		// b에서 벌 수 있는 돈 - (a->b까지 가는데 드는 비용) 값으로 갱신한다.
		for (int i = 0; i < transports.size(); i++) {
			transports[i][2] = moneys[transports[i][1]] - transports[i][2];
		}

		for (int i = 0; i < N * 2; i++) {

			for (auto transport : transports) {

				int a = transport[0];
				int b = transport[1];
				int cost = transport[2];

				if (dist[a] == -inf)
					continue;

				if (dist[a] + cost > dist[b]) {

					dist[b] = dist[a] + cost;

					// N번째 이상부터 갱신되는 경우는 사이클이 에 포함되어 있어서
					// 돈을 무한히 벌 수 있다는 의미이므로 값을 무한대 값으로 갱신한다.
					if (i >= N - 1)
						dist[b] = inf;
				}
			}
		}

		if (dist[end] == inf) {
			// 돈을 무한히 벌 수 있는 경우
			cout << "Gee" << endl;
		}
		else if (dist[end] == -inf) {
			// 도착지에 갈 수 없는 경우
			cout << "gg" << endl;
		}
		else {
			cout << dist[end] << endl;
		}
	}

	void execute() {

		int N, M, start, end;

		cin >> N >> start >> end >> M;

		vector<int> moneys(N, 0);
		vector<vector<int>> transports(M, vector<int>(3, 0));

		for (int i = 0; i < M; i++)
			cin >> transports[i][0] >> transports[i][1] >> transports[i][2];

		for (int i = 0; i < N; i++)
			cin >> moneys[i];

		solution(N, M, start, end, transports, moneys);
	}
}
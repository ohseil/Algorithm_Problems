#include "problem1.h"

namespace problem1 {

#define inf 2000000000

	void solution(int N, int M, int W, vector<vector<int>> roads, vector<vector<int>> warmholes) {

		// ���� 1�� ~ N��
		// ������� �ƹ� �������� ���ص� ��� �����Ƿ� ���� 1������ �Ѵ�.

		string answer = "NO";

		vector<int> dist(N + 1, inf);
		dist[1] = 0;

		// N�� ��� ������ Ȯ���Ѵ�.
		// ���ο� ����� ���� �� ��� ������ inf�� �ƴ� ��츸 ����.
		for (int i = 0; i < N; i++) {

			bool isUpdated = false;

			// ������ ��� ������̹Ƿ� �ΰ��� ��� ���.
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

			// ��Ȧ�� ��� �ѹ����̹Ƿ� �Ѱ����� ���.
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
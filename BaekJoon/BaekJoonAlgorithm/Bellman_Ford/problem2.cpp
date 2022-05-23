#include "problem2.h"

namespace problem2 {

#define inf 200000000

	void solution(int N, int M, vector<vector<int>> buses) {

		// dist �迭�� �ڷ����� long long�� ������
		// �������� �˰����� ���,
		// ��� �� ��ŭ ������ ���鼭 �� �������� ��� ������ �����ϴµ�
		// cycle�� ���� �ִ� ��� ��� �� x ���� �� ��ŭ ������ �Ѵ�.
		// ���� ���, a -> b -> c -> a �̷� �׷����� ����̴�.
		// �� �������� ����� ���� �ִ� 500, ������ ������ �ִ� 6000, ����ġ ���� �ּ� -10000 �̴�.
		// �׷� �� ��쿡 ������Ʈ�� ��� �ϸ� 500 * 6000 * (-10000)�� �� (-300��)���� ������Ʈ �ɰ��̴�.
		// �� ��쿡 int ������ �Ѿ�� �ȴ�.

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
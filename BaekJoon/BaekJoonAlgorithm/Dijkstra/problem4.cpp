#include "problem4.h"

#define inf 2000000000

void solution(int N, int M, int X, vector<vector<int>> roads) {

	// 각 사람마다 다익스트라를 시행하여 X까지의 최단거리를 저장하고
	// 시행하면서 사람이 X 도시 사람일 경우는 시행 결과가
	// X 도시부터 모든 도시의 사람들까지의 최단 경로이므로,
	// 이 결과 그대로 저장한다.
	// 그 후에 1번 도시의 사람부터 N번 도시의 사람까지
	// X까지의 최단거리 + X로부터의 최단거리를 비교하여 최대값 구하여 출력한다.

	unordered_map<int, vector<pair<int, int>>> roadMap;
	vector<int> toList(N + 1, 0);
	vector<int> fromList(N + 1, 0);

	for (auto road : roads)
		roadMap[road[0]].push_back(make_pair<int, int>((int)road[1], (int)road[2]));

	for (int p = 1; p <= N; p++) {

		vector<int> times(N + 1, inf);
		vector<int> visited(N + 1, 0);

		times[p] = 0;

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push(make_pair<int, int>(0, (int)p));

		while (pq.empty() == false) {

			int city = pq.top().second;
			int time = pq.top().first;
			pq.pop();

			if (visited[city] == 1)
				continue;

			for (auto road : roadMap[city]) {

				int nextCity = road.first;
				int nextTime = road.second;

				if (visited[nextCity] == 1)
					continue;

				if (time + nextTime < times[nextCity]) {
					times[nextCity] = time + nextTime;
					pq.push(make_pair<int, int>((int)times[nextCity], (int)nextCity));
				}
			}

			visited[city] = 1;
		}

		toList[p] = times[X];

		if (p == X)
			fromList = times;
	}

	int biggest = toList[1] + fromList[1];

	for (int p = 2; p <= N; p++)
		if (biggest < toList[p] + fromList[p])
			biggest = toList[p] + fromList[p];

	cout << biggest << endl;
}

namespace problem4 {

	void execute() {

		int N, M, X;

		cin >> N >> M >> X;

		vector<vector<int>> roads(M, vector<int>(3, 0));

		for (int i = 0; i < M; i++)
			cin >> roads[i][0] >> roads[i][1] >> roads[i][2];

		solution(N, M, X, roads);
	}
}
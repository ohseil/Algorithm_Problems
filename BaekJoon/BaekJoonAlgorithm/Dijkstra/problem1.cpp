#include "problem1.h"

namespace problem1 {

#define inf 10000000

	void solution(int V, int E, int start, vector<vector<int>> links) {

		unordered_map<int, vector<pair<int, int>>> linkMap;
		vector<int> dist(V + 1, inf);
		vector<int> visited(V + 1, 0);

		for (auto link : links)
			linkMap[link[0]].push_back(make_pair<int, int>((int)link[1], (int)link[2]));

		dist[start] = 0;

		// 우선순위 큐 사용. ( 오름차순 정렬하여 낮은 값 부터 삭제된다. )
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push(make_pair<int, int>((int)0, (int)start));

		while (pq.empty() == false) {

			int node = pq.top().second;
			int cost = pq.top().first;
			pq.pop();

			// 이미 방문한 노드라면 건너뛰기.
			if (visited[node] == 1)
				continue;

			for (auto link : linkMap[node]) {

				int nextNode = link.first;
				int nextCost = link.second;

				if (visited[nextNode] == 1)
					continue;

				if (dist[node] + nextCost < dist[nextNode]) {
					dist[nextNode] = dist[node] + nextCost;
					pq.push(make_pair<int, int>((int)dist[nextNode], (int)nextNode));
				}
			}

			visited[node] = 1;
		}

		for (int i = 1; i <= V; i++) {
			if (dist[i] == inf)
				printf_s("INF\n");
			else
				printf_s("%d\n", dist[i]);
		}
	}

	void execute() {

		int V, E, start;

		scanf_s("%d%d%d", &V, &E, &start);

		vector<vector<int>> links(E, vector<int>(3, 0));
		
		for (int i = 0; i < E; i++)
			scanf_s("%d%d%d", &links[i][0], &links[i][1], &links[i][2]);

		solution(V, E, start, links);
	}
}
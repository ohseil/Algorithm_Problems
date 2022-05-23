#include "problem2.h"

namespace problem2 {

#define inf 100000000

	void solution(int N, int M, vector<vector<int>> links, int start, int end) {

		// N : ���� ��
		// M : ���� ��
		// links : ������ ��� ����, ���� ����, ���
		// start : ��� ����
		// end : ���� ����

		// ��� ����, ���� ����, ��� map.
		unordered_map<int, vector<pair<int, int>>> linkMap;
		vector<int> dist(N + 1, inf); // ��� ���ú��� ������ ���ñ����� ���
		vector<int> visited(N + 1, 0); // �湮 ���

		for (auto link : links)
			linkMap[link[0]].push_back(make_pair<int, int>((int)link[1], (int)link[2]));

		dist[start] = 0;

		// first : �ش� node������ ���, second : node ��ȣ
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push(make_pair<int, int>(0, (int)start));

		while (pq.empty() == false) {

			pair<int, int> data = pq.top();
			pq.pop();

			int curCity = data.second;
			int curCost = data.first;

			if (visited[curCity] == 1) {
				// �̹� �湮 ��� ����.
				continue;
			}

			for (auto next : linkMap[curCity]) {

				int nextCity = next.first;
				int nextCost = next.second;

				if (visited[nextCity] == 1)
					continue;

				if (curCost + nextCost < dist[nextCity]) {
					dist[nextCity] = curCost + nextCost;
					pq.push(make_pair<int, int>((int)dist[nextCity], (int)nextCity));
				}
			}

			visited[curCity] = 1;
		}

		cout << dist[end] << endl;
	}

	void execute() {

		// ����� �ӵ� ������ ����.
		ios_base::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);

		int N, M, start, end;

		cin >> N >> M;

		vector<vector<int>> links(M, vector<int>(3, 0));
		
		for (int i = 0; i < M; i++)
			cin >> links[i][0] >> links[i][1] >> links[i][2];

		cin >> start >> end;

		solution(N, M, links, start, end);

	}
}
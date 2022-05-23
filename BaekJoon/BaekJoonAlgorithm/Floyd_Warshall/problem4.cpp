#include "problem4.h"

namespace problem4 {

// 맥주 20병 다 마실때까지 필요한 거리 1000m
#define beerM 1000

	void execute() {

		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int t;

		cin >> t;

		for (int c = 0; c < t; c++) {

			int n;
			cin >> n;

			// 집 번호 : 0번, 편의점 번호 : 1번 ~ n번, 페스티벌 번호 : n + 1번
			// 위의 번호로 한 인접행렬 생성.
			// 각 장소 사이의 거리가 1000m(맥주 20병 다 소비하는 거리) 넘어가면 갈 수 없으므로 -1,
			// 1000m 넘지 않으면 갈 수 있으므로 1로 설정한다.
			vector<vector<int>> links(n + 2, vector<int>(n + 2, -1));
			
			// 각 장소의 x,y 값을 저장한 map.
			map<int, pair<int, int>> pos;

			int x, y;

			// 집
			cin >> x >> y;
			pos[0].first = x;
			pos[0].second = y;

			// 편의점
			for (int i = 1; i <= n; i++) {
				cin >> x >> y;
				pos[i].first = x;
				pos[i].second = y;
			}

			// 페스티벌
			cin >> x >> y;
			pos[n + 1].first = x;
			pos[n + 1].second = y;

			for (int i = 0; i < n + 2; i++) {
				for (int j = 0; j < n + 2; j++) {
					// 장소 사이의 거리가 1000m 이하이면 이동 가능하므로 값 1로 갱신.
					if (abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second) <= beerM) {
						links[i][j] = 1;
					}
				}
			}

			for (int m = 0; m < n + 2; m++) {
				for (int s = 0; s < n + 2; s++) {
					for (int e = 0; e < n + 2; e++) {
						// s -> m 과 m -> e 두가지 경로 모두 갈 수 있으면 s->e 갈 수 있으므로 1로 갱신.
						links[s][e] = (links[s][m] == 1 && links[m][e] == 1) ? 1 : links[s][e];
					}
				}
			}

			// 집에서 페스티벌 갈 수 있는지 확인.
			if (links[0][n + 1] == 1)
				cout << "happy" << endl;
			else
				cout << "sad" << endl;

		}
	}
}
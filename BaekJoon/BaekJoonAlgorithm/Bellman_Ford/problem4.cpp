#include "problem4.h"

namespace problem4 {

#define inf 2000000000

	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	struct road {
		int x1, y1, x2, y2, cost;
		road(int a, int b, int c, int d, int e) :
			x1(a), y1(b), x2(c), y2(d), cost(e) {}
	};

	vector<vector<int>> dist(30, vector<int>(30, 0));
	vector<vector<int>> rips_or_holes(30, vector<int>(30, 0));
	vector<road> roads;

	void execute() {

		int W, H;
		int ripNum, holeNum;

		while (true) {

			scanf_s("%d%d", &W, &H);

			if (W == 0 && H == 0)
				break;

			for (int i = 0; i < 30; i++)
				for (int j = 0; j < 30; j++) {
					dist[i][j] = inf;
					rips_or_holes[i][j] = 0;
				}

			dist[0][0] = 0;

			roads.clear();

			scanf_s("%d", &ripNum);

			for (int i = 0; i < ripNum; i++) {

				int rw, rh;
				scanf_s("%d%d", &rw, &rh);
				rips_or_holes[rh][rw] = 1;
			}

			scanf_s("%d", &holeNum);

			for (int i = 0; i < holeNum; i++) {

				int a, b, c, d, e;
				scanf_s("%d%d%d%d%d", &a, &b, &c, &d, &e);
				rips_or_holes[b][a] = -1;
				roads.push_back(road(a, b, c, d, e));
			}

			// ==========================================================================

			for (int w = 0; w < W; w++) {
				for (int h = 0; h < H; h++) {

					if (rips_or_holes[h][w] != 0 || (w == W - 1 && h == H - 1))
						continue;

					for (int d = 0; d < 4; d++) {

						int nw = w + dx[d];
						int nh = h + dy[d];

						// 묘지의 범위 밖이 아니고 묘비가 없을 경우
						if ((0 <= nw && nw < W && 0 <= nh && nh < H) && rips_or_holes[nh][nw] != 1)
							roads.push_back(road(w, h, nw, nh, 1));

					}
				}
			}

			bool isCycle = false;

			for (int i = 0; i < W * H; i++) {

				for (auto r : roads) {

					int w = r.x1;
					int h = r.y1;
					int nw = r.x2;
					int nh = r.y2;
					int cost = r.cost;

					if (dist[h][w] == inf)
						continue;

					if (dist[h][w] + cost < dist[nh][nw]) {
						dist[nh][nw] = dist[h][w] + cost;

						if (i == W * H - 1)
							isCycle = true;
					}
				}
			}

			if (isCycle == true)
				printf_s("Never\n");
			else if (dist[H - 1][W - 1] == inf)
				printf_s("Impossible\n");
			else
				printf_s("%d\n", dist[H - 1][W - 1]);
		}

	}
}
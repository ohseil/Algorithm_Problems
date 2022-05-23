#include "problem4.h"

namespace problem4 {

// ���� 20�� �� ���Ƕ����� �ʿ��� �Ÿ� 1000m
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

			// �� ��ȣ : 0��, ������ ��ȣ : 1�� ~ n��, �佺Ƽ�� ��ȣ : n + 1��
			// ���� ��ȣ�� �� ������� ����.
			// �� ��� ������ �Ÿ��� 1000m(���� 20�� �� �Һ��ϴ� �Ÿ�) �Ѿ�� �� �� �����Ƿ� -1,
			// 1000m ���� ������ �� �� �����Ƿ� 1�� �����Ѵ�.
			vector<vector<int>> links(n + 2, vector<int>(n + 2, -1));
			
			// �� ����� x,y ���� ������ map.
			map<int, pair<int, int>> pos;

			int x, y;

			// ��
			cin >> x >> y;
			pos[0].first = x;
			pos[0].second = y;

			// ������
			for (int i = 1; i <= n; i++) {
				cin >> x >> y;
				pos[i].first = x;
				pos[i].second = y;
			}

			// �佺Ƽ��
			cin >> x >> y;
			pos[n + 1].first = x;
			pos[n + 1].second = y;

			for (int i = 0; i < n + 2; i++) {
				for (int j = 0; j < n + 2; j++) {
					// ��� ������ �Ÿ��� 1000m �����̸� �̵� �����ϹǷ� �� 1�� ����.
					if (abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second) <= beerM) {
						links[i][j] = 1;
					}
				}
			}

			for (int m = 0; m < n + 2; m++) {
				for (int s = 0; s < n + 2; s++) {
					for (int e = 0; e < n + 2; e++) {
						// s -> m �� m -> e �ΰ��� ��� ��� �� �� ������ s->e �� �� �����Ƿ� 1�� ����.
						links[s][e] = (links[s][m] == 1 && links[m][e] == 1) ? 1 : links[s][e];
					}
				}
			}

			// ������ �佺Ƽ�� �� �� �ִ��� Ȯ��.
			if (links[0][n + 1] == 1)
				cout << "happy" << endl;
			else
				cout << "sad" << endl;

		}
	}
}
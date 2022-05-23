#include "problem3.h"

namespace problem3 {

	void execute() {

		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int n, m;
		map<int, int> cards;

		cin >> n;

		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			cards[input] = 1;
		}

		cin >> m;

		for (int i = 0; i < m; i++) {
			int c;
			cin >> c;
			if (cards[c] == 1)
				cout << "1 ";
			else
				cout << "0 ";
		}

	}
}
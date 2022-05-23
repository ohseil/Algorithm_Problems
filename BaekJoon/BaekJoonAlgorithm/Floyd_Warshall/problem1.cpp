#include "problem1.h"

namespace problem1 {

	void solution(int n, vector<vector<int>> matrix) {

		// 플로이드 와샬 실행.
		for (int m = 0; m < n; m++) {
			for (int s = 0; s < n; s++) {
				for (int e = 0; e < n; e++) {
					matrix[s][e] = (matrix[s][m] && matrix[m][e]) ? 1 : matrix[s][e];
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}

	void execute() {

		int n;

		cin >> n;

		vector<vector<int>> matrix(n, vector<int>(n, 0));

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> matrix[i][j];

		solution(n, matrix);
	}
}
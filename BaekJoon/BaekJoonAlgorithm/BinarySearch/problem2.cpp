#include "problem2.h"

namespace problem2 {

	// �߸� ������ ���� ���ϴ� �Լ�
	long long sumTreeHeight(int sliceHeight, vector<int> trees) {
		
		long long sum = 0;

		for (int tree : trees)
			sum += (tree - sliceHeight > 0 ? tree - sliceHeight : 0);

		return sum;
	}

	void solution(int n, int m, vector<int> trees) {

		// 0 ~ 10����� �̺�Ž��.

		int left, mid, right, answer = 0;

		left = 0;
		right = 1000000000;

		while (left <= right) {

			mid = (left + right) / 2;

			if (sumTreeHeight(mid, trees) < m) {
				right = mid - 1;
			}
			else {
				answer = mid;
				left = mid + 1;
			}
		}

		cout << answer << endl;
	}

	void execute() {

		// n : ���� ��
		// m : ���������� ���� ����
		// �� ������ �ִ� ���̴� 10��.
		int n, m;

		vector<int> trees;

		cin >> n >> m;

		trees.assign(n, 0);
		for (int i = 0; i < n; i++)
			cin >> trees[i];

		solution(n, m, trees);
	}
}
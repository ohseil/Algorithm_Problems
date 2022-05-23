#include "problem4.h"

namespace problem4 {

	vector<int> A, B, C, D;
	vector<int> AB, CD;

	long long solution(int n) {

		long long answer = 0;

		// A[a] + B[b]�� ��� ����� ���� �ϳ��� �迭�� ����.
		// C[c] + D[d]�� ��� ����� ���� �ϳ��� �迭�� ����.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				AB.push_back(A[i] + B[j]);
				CD.push_back(C[i] + D[j]);
			}
		}

		// ������������ ����.
		sort(AB.begin(), AB.end());
		sort(CD.begin(), CD.end());

		int abIndex = 0, cdIndex = CD.size() - 1;

		// AB �迭������ index 0�� �����ͷ� ����.
		// CD �迭������ index CD.size() - 1�� �����ͷ� ����.
		// �������� �˰��� ����.
		while (true) {

			long long sum = AB[abIndex] + CD[cdIndex];

			if (sum == 0) {

				// ���� 0�̶��
				// ���� ���� ������ �ִ� ������ ��� ���� �� �����͸� �ű��.
				// (AB�迭������ ���� �� ���� x CD�迭������ ���� �� ����) �� ���Ѵ�.
				// ex) AB = {-3,-3, 0, 0, 1}, CD = {-2,-1,-1,3,3}
				//     �̷� ��쿡 �Ϲ����� �������� �˰��� ������ �����ϸ�
				//     -3�� 3�� ������ ������ 2���ۿ� ���� ���Ѵ�.
				//     �����δ� -3�� ���� x 3�� ���� --> 2 x 2 = 4���� ���;� �Ѵ�.

				int abData = AB[abIndex];
				int cdData = CD[cdIndex];

				long long abCount = 0, cdCount = 0;

				while (abIndex < CD.size() && AB[abIndex] == abData) {
					abCount++;
					abIndex++;
				}

				while (cdIndex >= 0 && CD[cdIndex] == cdData) {
					cdCount++;
					cdIndex--;
				}

				answer += (abCount * cdCount);
			}
			else if (sum >= 0) cdIndex--;
			else abIndex++;

			if (abIndex >= CD.size() || cdIndex < 0)
				break;
		}

		return answer;
	}

	void execute() {

		int n;

		/*cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> A[i];
			cin >> B[i];
			cin >> C[i];
			cin >> D[i];
		}*/

		n = 6;

		A.assign(n, 0);
		B.assign(n, 0);
		C.assign(n, 0);
		D.assign(n, 0);

		A[0] = -45; B[0] = 22; C[0] = 42; D[0] = -16;
		A[1] = -41; B[1] = -27; C[1] = 56; D[1] = 30;
		A[2] = -36; B[2] = 53; C[2] = -37; D[2] = 77;
		A[3] = -36; B[3] = 30; C[3] = -75; D[3] = -46;
		A[4] = 26; B[4] = -38; C[4] = -10; D[4] = 62;
		A[5] = -32; B[5] = -54; C[5] = -6; D[5] = 45;

		cout << solution(n) << endl;

	}
}
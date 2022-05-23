#include "problem4.h"

namespace problem4 {

	vector<int> A, B, C, D;
	vector<int> AB, CD;

	long long solution(int n) {

		long long answer = 0;

		// A[a] + B[b]의 모든 경우의 수를 하나의 배열로 생성.
		// C[c] + D[d]의 모든 경우의 수를 하나의 배열로 생성.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				AB.push_back(A[i] + B[j]);
				CD.push_back(C[i] + D[j]);
			}
		}

		// 오름차순으로 정렬.
		sort(AB.begin(), AB.end());
		sort(CD.begin(), CD.end());

		int abIndex = 0, cdIndex = CD.size() - 1;

		// AB 배열에서는 index 0을 포인터로 지정.
		// CD 배열에선느 index CD.size() - 1을 포인터로 지정.
		// 투포인터 알고리즘 실행.
		while (true) {

			long long sum = AB[abIndex] + CD[cdIndex];

			if (sum == 0) {

				// 합이 0이라면
				// 같은 수가 여러개 있는 경우들을 모두 구한 후 포인터를 옮긴다.
				// (AB배열에서의 같은 수 개수 x CD배열에서의 같은 수 개수) 를 더한다.
				// ex) AB = {-3,-3, 0, 0, 1}, CD = {-2,-1,-1,3,3}
				//     이런 경우에 일반적인 투포인터 알고리즘 과정을 수행하면
				//     -3과 3의 조합의 개수를 2개밖에 세지 못한다.
				//     실제로는 -3의 개수 x 3의 개수 --> 2 x 2 = 4개가 나와야 한다.

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
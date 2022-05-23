#include "problem1.h"

namespace problem1 {

	vector<int> solution(vector<int> datas, vector<int> queries) {

		vector<int> answer;

		// 오름차순 정렬
		sort(datas.begin(), datas.end());

		int left, mid, right;

		for (int num : queries) {

			left = 0;
			right = datas.size() - 1;

			bool isNum = false;

			while (left <= right) {

				mid = (left + right) / 2;

				if (datas[mid] < num) {
					left = mid + 1;
				}
				else if (datas[mid] > num) {
					right = mid - 1;
				}
				else if (datas[mid] == num) {
					isNum = true;
					break;
				}
			}

			if (isNum)
				answer.push_back(1);
			else
				answer.push_back(0);
		}

		return answer;
	}

	void execute() {

		int n, m;
		vector<int> datas, queries, answer;

		cin >> n;
		datas.assign(n, 0);
		for (int i = 0; i < n; i++)
			cin >> datas[i];

		cin >> m;
		queries.assign(m, 0);
		for (int i = 0; i < m; i++)
			cin >> queries[i];

		map<int, int> mm;

		for (auto d : datas)
			mm[d] = 1;

		for (auto q : queries)
			if (mm[q] == 1)
				answer.push_back(1);
			else
				answer.push_back(0);

		for (auto a : answer)
			printf("%d\n", a);
	}
}
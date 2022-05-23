#include "problem4.h"

namespace problem4 {

	unordered_map<int, vector<int>> treeMap;
	int dp[100001][18], visited[100001]{ 0, };
	
	void cal(int node) {

		visited[node] = 1;

		for (auto child : treeMap[node]) {

			if (visited[child] == 1)
				continue;

			cal(child);

			for (int nodeColor = 1; nodeColor < 18; nodeColor++) {
				// �θ����� ���� ������ �� ��
				// dp���� ���� ���� ���� ã�Ƽ� �����ش�.

				int minValue = 1000000000;
				for (int childColor = 1; childColor < 18; childColor++) {
					if (childColor != nodeColor && minValue > dp[child][childColor])
						minValue = dp[child][childColor];
				}

				dp[node][nodeColor] += minValue;
			}
		}

		// ����� �� ���� ���ϱ�.
		for (int nodeColor = 1; nodeColor < 18; nodeColor++)
			dp[node][nodeColor] += nodeColor;
	}

	int solution(vector<vector<int>> links) {

		// 1. tree map ����.
		// 2. dp process ����.

		// dp[n][c] = ��� n�� c���� ���� �ּҰ�. (�ڽĵ��� dp���� c���� �ƴ� ���� �ּҰ����� ���Ѵ�.)

		// node�� ������ �ִ� 10�����̰� ��밡�� ���� 10����������
		// ������ ���Ǵ� ���� �ִ� 17��.

		// ������ ���Ǵ� �� ���ϱ�.
		// p���� ���� ����ؼ� ���� �� �ִ� Ʈ���� �ּ� ũ�⸦ T[p]��� ����.
		// ���⼭ Ʈ���� ũ��� ����� ���� �ǹ��Ѵ�.
		
		// �� ������ : 1 2 3 4 5 ...
		// T[p]      : 1 2 4 8 16 ...

		// ���� ���� p���� ���� ������� �� ���� �� �ִ� Ʈ���� �ּ� ��� ������
		// 2^p-1 ��Ģ�� ���δ�.
		// �ᱹ �־��� ������ node�� �ִ� ������ 10�����̹Ƿ�,
		// 2^p-1 = 100000 ---> p = (���� 2�� log100000) + 1 �� �ȴ�.
		// �ᱹ �ִ� 17���� ���� ����ϰ� �ȴ�.
		
		// �߰�����) 17���� ���� ������� �� ���� �� �ִ� Ʈ���� �ּ� ��尳���� 10���� �Ѵ´�.
		// �ᱹ ������ ���Ǵ� ���� �������� �־��� ���ǿ� ������ 17���� �ѱ� �� ����.

		// �׷� 17���� ���� ����ҰŸ� 1~10���� ���� ���� ���߿� �翬�� ���� ���� ������
		// ���ʴ�� 17���� ���� ����ϴ� ���� Ʈ������ ����Ǵ� ���� �ּ� ���� ���ϴ� ���̴�.

		int answer = 1000000000;

		for (auto link : links) {
			treeMap[link[0]].push_back(link[1]);
			treeMap[link[1]].push_back(link[0]);
		}

		cal(1);

		for (int i = 1; i < 18; i++)
			if (answer > dp[1][i])
				answer = dp[1][i];

		return answer;
	}

	void execute() {

		int n;
		vector<vector<int>> links;

		/*cin >> n;
		for (int i = 0; i < n; i++) {
			vector<int> link(2, 0);
			cin >> link[0] >> link[1];
			links.push_back(link);
		}*/

		n = 8;
		vector<int> v(2, 0);
		v[0] = 1; v[1] = 2;
		links.push_back(v);
		v[0] = 3; v[1] = 1;
		links.push_back(v);
		v[0] = 1; v[1] = 4;
		links.push_back(v);
		v[0] = 5; v[1] = 6;
		links.push_back(v);
		v[0] = 1; v[1] = 5;
		links.push_back(v);
		v[0] = 5; v[1] = 7;
		links.push_back(v);
		v[0] = 5; v[1] = 8;
		links.push_back(v);

		cout << solution(links) << endl;
	}
}
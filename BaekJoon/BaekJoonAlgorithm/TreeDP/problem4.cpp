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
				// 부모노드의 색을 제외한 색 중
				// dp값이 가장 적은 값을 찾아서 더해준다.

				int minValue = 1000000000;
				for (int childColor = 1; childColor < 18; childColor++) {
					if (childColor != nodeColor && minValue > dp[child][childColor])
						minValue = dp[child][childColor];
				}

				dp[node][nodeColor] += minValue;
			}
		}

		// 노드의 색 값을 더하기.
		for (int nodeColor = 1; nodeColor < 18; nodeColor++)
			dp[node][nodeColor] += nodeColor;
	}

	int solution(vector<vector<int>> links) {

		// 1. tree map 생성.
		// 2. dp process 실행.

		// dp[n][c] = 노드 n이 c색일 때의 최소값. (자식들의 dp값중 c색이 아닌 색중 최소값들을 더한다.)

		// node의 개수는 최대 10만개이고 사용가능 색도 10만개이지만
		// 실제로 사용되는 색은 최대 17개.

		// 실제로 사용되는 색 구하기.
		// p개의 색을 사용해서 만들 수 있는 트리의 최소 크기를 T[p]라고 하자.
		// 여기서 트리의 크기는 노드의 수를 의미한다.
		
		// 색 가지수 : 1 2 3 4 5 ...
		// T[p]      : 1 2 4 8 16 ...

		// 위와 같이 p가지 색을 사용했을 때 만들 수 있는 트리의 최소 노드 개수는
		// 2^p-1 규칙이 보인다.
		// 결국 주어진 조건이 node의 최대 개수가 10만개이므로,
		// 2^p-1 = 100000 ---> p = (밑이 2인 log100000) + 1 이 된다.
		// 결국 최대 17개의 색만 사용하게 된다.
		
		// 추가설명) 17개의 색을 사용했을 때 만들 수 있는 트리의 최소 노드개수가 10만이 넘는다.
		// 결국 실제로 사용되는 색의 가지수는 주어진 조건에 따르면 17개를 넘길 수 없다.

		// 그럼 17개의 색을 사용할거면 1~10만의 값을 가진 색중에 당연히 제일 작은 값부터
		// 차례대로 17개의 색을 사용하는 것이 트리에서 적용되는 값의 최소 값을 구하는 길이다.

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
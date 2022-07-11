#include "모두_0으로_만들기.h"
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

모두_0으로_만들기_BEGIN

long long solution(vector<int> a, vector<vector<int>> edges) {

    // 트리의 리프 노드들부터 bfs를 실행한다.
    // n개의 노드와 연결 된 노드로 이동할 때는,
    // 연결 된 n-1개의 경로가 모두 탐색 된 후에
    // 연결이 1개만 남았을 때만 이동한다.

    // 노드의 모든 가중치를 합했을 때,
    // 0이 되지 않는다면 모든 노드를 0으로 만들 수 없다.
    long long total_cost = 0;

    for (int n : a)
        total_cost += n;

    if (total_cost != 0)
        return -1;

    long long answer = 0;
    vector<long long> node_v;
    map<int, vector<int>> edge_m;

    for (int value : a)
        node_v.emplace_back(value);

    for (vector<int> edge : edges) {
        edge_m[edge[0]].push_back(edge[1]);
        edge_m[edge[1]].push_back(edge[0]);
    }

    queue<int> q;
    vector<int> validation_v(a.size());

    for (auto edge : edge_m) {

        validation_v[edge.first] = edge.second.size();

        if (edge.second.size() == 1)
            q.push(edge.first);
    }

    while (q.empty() == false) {

        int qsize = q.size();

        for (int i = 0; i < qsize; i++) {

            int node = q.front();
            q.pop();

            for (int next : edge_m[node]) {

                if (validation_v[next] == 0)
                    continue;

                node_v[next] += node_v[node];
                answer += abs(node_v[node]);
                node_v[node] = 0;
                validation_v[node] = 0;
                validation_v[next]--;

                if (validation_v[next] == 1) {
                    q.push(next);
                }
            }
        }
    }

    return answer;
}

void service() {

    vector<int> a = { -5,0,2,1,2 };
    vector<vector<int>> e = { {0,1},{3,4},{2,3},{0,3} };
    cout << solution(a, e) << endl;
}

모두_0으로_만들기_END
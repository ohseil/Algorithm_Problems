#include "���_0����_�����.h"
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

���_0����_�����_BEGIN

long long solution(vector<int> a, vector<vector<int>> edges) {

    // Ʈ���� ���� ������� bfs�� �����Ѵ�.
    // n���� ���� ���� �� ���� �̵��� ����,
    // ���� �� n-1���� ��ΰ� ��� Ž�� �� �Ŀ�
    // ������ 1���� ������ ���� �̵��Ѵ�.

    // ����� ��� ����ġ�� ������ ��,
    // 0�� ���� �ʴ´ٸ� ��� ��带 0���� ���� �� ����.
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

���_0����_�����_END
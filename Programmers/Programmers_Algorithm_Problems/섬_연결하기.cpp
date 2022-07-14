#include "��_�����ϱ�.h"
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

��_�����ϱ�_BEGIN

int solution(int n, vector<vector<int>> costs) {
    
    // �׷����� �ּҽ���Ʈ�� ã��
    // prim �˰��� ���.

    int answer = 0;
    
    map<int, vector<pair<int, int>>> route_m;
    priority_queue<pair<int, pair<int, int>>> pq;   
    vector<bool> validation_v(n, false);

    for (vector<int> cost : costs) {
        route_m[cost[0]].emplace_back(cost[1], cost[2]);
        route_m[cost[1]].emplace_back(cost[0], cost[2]);
    }

    // 0�� ������ ����.
    for (pair<int, int> route : route_m[0])
        pq.push({ -route.second, {0, route.first} });
    
    validation_v[0] = true;

    while (pq.empty() == false) {

        pair<int, pair<int, int>> edge = pq.top();
        pq.pop();

        int a = edge.second.first;
        int b = edge.second.second;
        int cost = -edge.first;

        if (validation_v[b] == true)
            continue;

        answer += cost;

        for (pair<int, int> route : route_m[b])
            pq.push({ -route.second, {b, route.first} });

        validation_v[b] = true;
    }

    return answer;
}

void service() {

    int n = 4;
    vector<vector<int>> c = { {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} };
    cout << solution(n, c) << endl;
}

��_�����ϱ�_END
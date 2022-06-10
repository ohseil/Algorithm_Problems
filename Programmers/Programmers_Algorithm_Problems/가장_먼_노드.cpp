#include "����_��_���.h"
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

����_��_���_BEGIN

#define INF 2100000000

int solution(int n, vector<vector<int>> edge) {
    
    // ���ͽ�Ʈ�� �˰��� ����ؼ�
    // 1�� ������ ������ �ٸ� �������� �ִܰŸ� ���ϱ�.
    // ���� ������ ����Ʈ�� ������������ �����ؼ� �ִ� ���� ����� ���� ã��.
    
    int answer = 0;
    
    map<int, set<int>> edge_map;

    vector<int> dist(n + 1, INF);
    vector<int> visited(n + 1, 0);
    dist[0] = dist[1] = 0;

    for (auto e : edge) {
        edge_map[e[0]].insert(e[1]);
        edge_map[e[1]].insert(e[0]);
    }

    for (int i = 0; i < n; i++) {

        int stand;
        int stand_dist = INF;

        for (int node = 1; node <= n; node++) {
            if (visited[node] == 1)
                continue;
            if (stand_dist > dist[node]) {
                stand = node;
                stand_dist = dist[node];
            }
        }

        visited[stand] = 1;

        for (int next : edge_map[stand]) {
            if (dist[next] < INF)
                continue;
            dist[next] = dist[stand] + 1;
        }
    }

    sort(dist.begin(), dist.end(), greater<>());

    for (int i = 0; i <= n; i++)
        if (dist[i] == dist[0])
            answer++;

    return answer;
}

void service() {

    int n = 6;
    vector<vector<int>> v = { {3,6},{4,3},{3,2},{1,3},{1,2},{2,4},{5,2} };
    cout << solution(n, v) << endl;
    
}

����_��_���_END
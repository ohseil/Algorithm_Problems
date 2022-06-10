#include "가장_먼_노드.h"
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

가장_먼_노드_BEGIN

#define INF 2100000000

int solution(int n, vector<vector<int>> edge) {
    
    // 다익스트라 알고리즘 사용해서
    // 1번 노드부터 나머지 다른 노드까지의 최단거리 구하기.
    // 구한 데이터 리스트를 내림차순으로 정렬해서 최댓 값인 노드의 개수 찾기.
    
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

가장_먼_노드_END
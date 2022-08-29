#include "등산코스_정하기.h"
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

등산코스_정하기_BEGIN

#define LIMIT_INTENSITY 10000001
#define umap unordered_map

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {

    // BFS + 백트래킹
    // 왕복이라고 하더라도 편도 루트만 구하면 된다.
    // 최소 intensity의 루트를 찾으면 같은 루트로 돌아오면 되기 때문에.
    // 모든 출입구를 시작점으로 해서 bfs를 실행한다.
    // 각 출입구마다 bfs를 실행하면 시간 초과가 발생한다.
    // 어떤 출입구에서 시작하더라도 최소 intensity 루트만 찾으면 되기 때문에
    // 모든 출입구에서 동시에 bfs를 진행해도 된다.
    
    // 다음 경로를 갈지 말지 정할 때,
    // 확인이 필요한 조건은 2가지가 있다.
    // 1. 출입구가 아닌 경우, 2. 가려는 위치의 intensity보다 현재 루트의 intensity가 작은 경우
    // 각 위치에서의 intensity를 저장할 배열을 사용한다.
    // 출입구의 intensity는 0이고 나머지는 limit intensity 값으로 설정한다.
    // 다음 위치의 intensity보다 현재 루트의 intensity가 작은 경우에만 진행하게 되면
    // 2가지 조건 모두 만족할 수 있다.

    // 종료 조건은 이동한 곳이 봉우리인 경우다.
    // 봉우리인 경우 탐색을 종료한다.
    
    // bfs 후에 intensity 배열을 모두 확인해서 봉우리의 intensity를 비교한다.

    vector<int> answer = { n, LIMIT_INTENSITY };

    umap<int, umap<int, int>> edgeMap;
    vector<int> gateMap(n + 1, 0);
    vector<int> summitMap(n + 1, 0);

    for (vector<int> path : paths) {
        edgeMap[path[0]][path[1]] = path[2];
        edgeMap[path[1]][path[0]] = path[2];
    }

    for (int gate : gates)
        gateMap[gate] = 1;
    for (int summit : summits)
        summitMap[summit] = 1;

    vector<int> intensities(n + 1, LIMIT_INTENSITY);

    queue<pair<int, int>> q;

    for (int gate : gates) {
        q.push({ gate, 0 });
        intensities[gate] = 0;
    }

    while (q.empty() == false) {

        int node = q.front().first;
        int intensity = q.front().second;
        q.pop();

        if (summitMap[node] == 1)
            continue;

        for (auto nextInform : edgeMap[node]) {

            int next = nextInform.first;
            int cost = nextInform.second;

            int nIntensity = max(intensity, cost);

            if (intensities[next] <= nIntensity)
                continue;

            q.push({ next, nIntensity });
            intensities[next] = nIntensity;
        }
    }

    for (int node = 1; node <= n; node++) {

        if (summitMap[node] == 0)
            continue;

        if (intensities[node] < answer[1]) {
            answer = { node, intensities[node]};
        }
        else if (intensities[node] == answer[1]) {
            if (node < answer[0])
                answer = { node, intensities[node]};
        }
    }

    return answer;
}

void service() {

    int n = 7;
    vector<vector<int>> p = { {1,4,4},{1,6,1},{1,7,3},{2,5,2},
                              {3,7,4},{5,6,6} };
    vector<int> g = { 1 };
    vector<int> s = { 2,3,4 };

    vector<int> ans = solution(n, p, g, s);
    cout << ans[0] << " " << ans[1] << endl;
}

등산코스_정하기_END
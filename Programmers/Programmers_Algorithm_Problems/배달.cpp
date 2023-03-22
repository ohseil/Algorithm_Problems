#include "배달.h"
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

배달_BEGIN

#define INF 20000000

#define RoadInform pair<int, int>
#define HashMap unordered_map

HashMap<int, HashMap<int, int>> roadMap;
vector<int> minCostsOfRoute;

void setRoadMap(vector<vector<int>>& roads) {

    for (vector<int> road : roads) {
        int a = road[0];
        int b = road[1];
        int time = road[2];

        if (roadMap[a][b] == 0
            || time < roadMap[a][b]) {
            roadMap[a][b] = roadMap[b][a] = time;
        }
    }
}

void setMinCostsOfRoute(int n) {
    minCostsOfRoute.assign(n + 1, INF);
}

// 다익스트라
void findMinCostInAllRoute() {

    priority_queue<RoadInform> pq;

    pq.push({ 0, 1 });

    while (pq.empty() == false) {

        RoadInform roadInform = pq.top();
        pq.pop();

        int country = roadInform.second;
        int necessaryTime = -roadInform.first;

        if (minCostsOfRoute[country] != INF)
            continue;

        minCostsOfRoute[country] = necessaryTime;

        for (auto road : roadMap[country]) {

            int nextCountry = road.first;
            int roadCost = road.second;

            pq.push(RoadInform(-(necessaryTime + roadCost), nextCountry));
        }
    }
}

int getCanDeliverCountryCount(int limitTime) {

    int canDeliverCountryCount = 0;

    for (int i = 1; i < minCostsOfRoute.size(); i++) {

        int necessaryTime = minCostsOfRoute[i];

        if (necessaryTime <= limitTime)
            canDeliverCountryCount++;
    }

    return canDeliverCountryCount;
}

int solution(int N, vector<vector<int>> road, int K) {
    
    // 다익스트라 알고리즘을 이용해서
    // 1번 마을부터 모든 마을까지의 최단 시간을 구한다.
    
    // 그리고 K 이하의 시간이 걸리는 마을의 개수를 센다.

    // 다익스트라 이전에 road 배열을 참조해서
    // 마을 간의 경로 정보를 hash map에 저장해서 사용한다.
    // 이 때, 두 마을 사이에 여러 개의 경로 정보가 있을 수 있다.
    // 여러 경로들 중에 가장 적게 걸리는 시간만 저장한다.

    int answer = 0;

    setRoadMap(road);
    setMinCostsOfRoute(N);
    findMinCostInAllRoute();

    answer = getCanDeliverCountryCount(K);

    return answer;
}

void service() {

    int n = 5;
    vector<vector<int>> roads = { {1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2} };
    int k = 3;

    cout << solution(n, roads, k) << endl;
}

배달_END
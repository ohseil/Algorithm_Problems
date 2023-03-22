#include "���.h"
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

���_BEGIN

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

// ���ͽ�Ʈ��
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
    
    // ���ͽ�Ʈ�� �˰����� �̿��ؼ�
    // 1�� �������� ��� ���������� �ִ� �ð��� ���Ѵ�.
    
    // �׸��� K ������ �ð��� �ɸ��� ������ ������ ����.

    // ���ͽ�Ʈ�� ������ road �迭�� �����ؼ�
    // ���� ���� ��� ������ hash map�� �����ؼ� ����Ѵ�.
    // �� ��, �� ���� ���̿� ���� ���� ��� ������ ���� �� �ִ�.
    // ���� ��ε� �߿� ���� ���� �ɸ��� �ð��� �����Ѵ�.

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

���_END
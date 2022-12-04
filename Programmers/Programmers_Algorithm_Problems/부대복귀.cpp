#include "부대복귀.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

부대복귀_BEGIN

#define HashMap unordered_map

#define MAX_COST 500001
#define COST_PER_ROAD 1

HashMap<int, HashMap<int, int>> roadMap;
int* shortestDistFromDestinationList;

void init(const int n) {

    shortestDistFromDestinationList = new int[n];
    
    for (int i = 1; i <= n; i++)
        shortestDistFromDestinationList[i] = MAX_COST;

}

void makeRoadMap(const vector<vector<int>>& roads) {

    for (vector<int> road : roads) {

        int a = road[0];
        int b = road[1];

        roadMap[a][b] = 1;
        roadMap[b][a] = 1;

    }
}

void findShortestDistFromDestinationToAllRegion(const int destination) {

    queue<int> q;

    q.push(destination);
    shortestDistFromDestinationList[destination] = 0;

    while (q.empty() == false) {
        
        int regionNum = q.front();
        int distToRegion = shortestDistFromDestinationList[regionNum];

        q.pop();

        for (auto roadToNextRegion : roadMap[regionNum]) {

            int nextRegionNum = roadToNextRegion.first;
            int distToNextRegion = shortestDistFromDestinationList[nextRegionNum];

            if (distToRegion + COST_PER_ROAD >= distToNextRegion)
                continue;

            shortestDistFromDestinationList[nextRegionNum] = distToRegion + COST_PER_ROAD;
            q.push(nextRegionNum);

        }
    }
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    
	/*

		목적지를 출발점으로 해서 모든 지역까지 최단 거리를 BFS로 구한다.
		만약 길을 통과하는데 걸리는 시간이 고정되어 있지 않았다면,
		다익스트라 알고리즘을 사용했을 것이다.
		하지만 걸리는 시간이 고정되어 있기 때문에,
		BFS만 사용해도 모든 지역까지의 최단 거리를 구할 수 있다.

	 */

    vector<int> answer;

    init(n);
    makeRoadMap(roads);
    findShortestDistFromDestinationToAllRegion(destination);

    for (int memberPos : sources) {

        int shortestDist = shortestDistFromDestinationList[memberPos];

        answer.push_back((shortestDist < MAX_COST) ? shortestDist : -1);

    }

    return answer;
}

void service() {

    int n = 3;
    vector<vector<int>> roads = { {1,2},{2,3} };
    vector<int> sources = { 2,3 };
    int destination = 1;

    vector<int> answer = solution(n, roads, sources, destination);

    for (int a : answer)
        cout << a << " ";
    cout << endl;

}

부대복귀_END
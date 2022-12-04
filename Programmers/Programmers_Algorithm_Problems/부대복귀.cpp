#include "�δ뺹��.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

�δ뺹��_BEGIN

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

		�������� ��������� �ؼ� ��� �������� �ִ� �Ÿ��� BFS�� ���Ѵ�.
		���� ���� ����ϴµ� �ɸ��� �ð��� �����Ǿ� ���� �ʾҴٸ�,
		���ͽ�Ʈ�� �˰����� ������� ���̴�.
		������ �ɸ��� �ð��� �����Ǿ� �ֱ� ������,
		BFS�� ����ص� ��� ���������� �ִ� �Ÿ��� ���� �� �ִ�.

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

�δ뺹��_END
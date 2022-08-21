#include "양과_늑대.h"
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_set>

using namespace std;

양과_늑대_BEGIN

#define uset unordered_set

int solution(vector<int> info, vector<vector<int>> edges) {
    
    // 완전 탐색 + 백트래킹을 사용했다.
    // 일단 루트노드부터 시작한다.
    // 루트 노드에 위치한 상태에서 양의 수는 1이고 늑대 수는 0이다.
    // 루트의 자식 노드들로 이동이 가능하다.
    // 이후에도 같은 방식으로 방문했던 노드들의 자식 노드들을 모두 확인해서 이동할 수 있는 모든 곳으로 이동한다.
    
    // 이 때, 이동 가능한 노드를 찾는 방법은
    // 이동 루트마다 이전에 방문한 노드를 hash set 형태로 저장해 놓고 사용한다.
    // 리스트에 있는 노드들을 모두 순회해서 자식들을 모두 확인한다.
    // 이 때, 이미 노드 리스트에 포함 된 자식 노드로는 이동할 수 없고,
    // 이동했을 때 늑대 수가 양의 수 이상이 되는 경우도 이동할 수 없다.

    int answer = 0;
    
    map<int, vector<int>> tree;

    for (vector<int> edge : edges) {
        tree[edge[0]].push_back(edge[1]);
    }

    // <방문노드 리스트, <양, 늑대>>
    queue<pair<uset<int>, pair<int, int>>> q;

    q.push({ { 0 }, { 1, 0 } });

    while (q.empty() == false) {

        pair<uset<int>, pair<int, int>> data = q.front();
        q.pop();

        uset<int> nodeSet = data.first;
        int sheepCount = data.second.first;
        int wolfCount = data.second.second;

        if (sheepCount > answer)
            answer = sheepCount;

        for (int node : nodeSet) {
            for (int child : tree[node]) {
                
                if (nodeSet.count(child) > 0)
                    continue;
                if (info[child] == 1 && sheepCount <= wolfCount + 1)
                    continue;

                uset<int> nextSet = nodeSet;
                nextSet.insert(child);

                if (info[child] == 0)
                    q.push({ nextSet, { sheepCount + 1, wolfCount } });
                else
                    q.push({ nextSet, { sheepCount, wolfCount + 1 } });

            }
        }
    }

    return answer;
}

void service() {

    vector<int> info = { 0,0,1,1,1,0,1,0,1,0,1,1 };
    vector<vector<int>> e = { {0,1},{1,2},{1,4},{0,8},{8,7},{9,10},
                                {9,11},{4,3},{6,5},{4,6},{8,9} };

    cout << solution(info, e) << endl;
}

양과_늑대_END
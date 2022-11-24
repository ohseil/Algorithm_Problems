#include "등대.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

등대_BEGIN

#define HashMap unordered_map
#define HashSet unordered_set

class TreeNode {
public:
    int num;
    vector<TreeNode*> childs;
    TreeNode(int num) : num(num) {}
};

HashMap<int, vector<int>> routeMap;
TreeNode* routeNode;

HashSet<int> turnedOnLighthouseSet;
int theMinNumOfLighthouseTurnedOn = 0;

void makeRouteMap(int n, vector<vector<int>>& lighthouse) {

    for (vector<int> route : lighthouse) {
        routeMap[route[0]].push_back(route[1]);
        routeMap[route[1]].push_back(route[0]);
    }
}

void findRouteNode(int maxNodeNum) {

    for (int fromNode = 1; fromNode <= maxNodeNum; fromNode++) {
        
        vector<int> toRoutes = routeMap[fromNode];

        if (toRoutes.size() > 1) {
            routeNode = new TreeNode(fromNode);
            break;
        }
    }
}

void makeTree() {

    queue<TreeNode*> q;
    HashSet<int> visitedNodeSet;

    q.push(routeNode);
    visitedNodeSet.insert(routeNode->num);

    while (q.empty() == false) {

        TreeNode* node = q.front();
        q.pop();

        for (int toNodeInRoute : routeMap[node->num]) {

            // 부모 노드로 향하는 루트 필터링
            if (visitedNodeSet.count(toNodeInRoute) > 0)
                continue;

            TreeNode* child = new TreeNode(toNodeInRoute);
            node->childs.push_back(child);
            q.push(child);
            visitedNodeSet.insert(child->num);
        }

    }
}

void countTheMinNumberOfTurnedOnLighthouse(TreeNode* parent) {

    if (parent->childs.empty() == true)
        return;

    bool isMustTurnOn = false;

    for (TreeNode* child : parent->childs) {

        countTheMinNumberOfTurnedOnLighthouse(child);

        if (turnedOnLighthouseSet.count(child->num) == 0)
            isMustTurnOn = true;
    }

    if (isMustTurnOn == true)
        turnedOnLighthouseSet.insert(parent->num);

}

int solution(int n, vector<vector<int>> lighthouse) {
    
    int answer = 0;
    
    makeRouteMap(n, lighthouse);
    findRouteNode(n);
    makeTree();
    countTheMinNumberOfTurnedOnLighthouse(routeNode);

    answer = turnedOnLighthouseSet.size();

    return answer;
}

void service() {

    int n = 8;
    vector<vector<int>> routes = { {1,2},{1,3},{1,4},{1,5},{5,6},{5,7},{5,8} };

    cout << solution(n, routes);
}

등대_END
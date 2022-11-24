#include "���.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

���_BEGIN

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

    // ��밡 2���� ��� 2�� �̻� ��ΰ� �ִ� ��밡 ��� ���� ó��.
    if (routeNode == nullptr) routeNode = new TreeNode(1);
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

            // �θ� ���� ���ϴ� ��Ʈ ���͸�
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
    
	// �⺻ ������ ���� ���� ����Ǿ� �ִ� ��븦 ���� ��,
	// �ش� ���� ���� �� ��� �� �ϳ��� ������ �Ѵ�.
	// �׷��ٸ� ������ ���� �� ��븦 ������ ���� ����.
	// ���� �� ���� 2���� ���� ����Ǿ� �ֱ� �����̴�.
	// �� �� �ϳ��� ������ ������ �Ѵٸ� ���� �� ��븦 ������ ������ �Ѵ�.

	// �� �������κ��� �ذ� ����� �����ߴ�.
	// ��볢�� ���� �� ����� n-1���̱� ������ Ʈ�� ������ �� �� �ִ�.
	// �׷��ٸ�, 2�� �̻��� ���� ���� �� ��带 ��Ʈ ���� �ؼ� Ʈ���� ���� �� �ִ�.
	// Ʈ���� ����� ������ �����ߴ� ���� ���� ���� ������ �ȴ�.

	// ���� ������ ���� ���� �ؼ�
	// �� ���� ���� ���� �� ��븦 ������, ���� ���� �� ���� ������ �ʴ� ������ �����Ѵ�.
	// �׸��� �� ���� Ʈ���� ���� ���� Ʈ���� ��Ʈ ���� 2�� �̻��� ���� ���� �� ����.
    // �� ���� ���� ��Ĵ�� ��������, ��� ��� ���ؿ����� ������ �ʴ� ��밡 �ǰ�
    // ��� ��� ���ؿ����� ������ ��밡 �ȴ�.
    // ���� �� �ڽ� ����� ������ ����� ������ ��,
    // ��� �ڽ� ������ ������ �ִٸ� ���� Ʈ���� ��Ʈ ��� ���� ������ �ʴ´�.
    // ������ �ϳ��� ������ ���� ���� �ڽ� ��밡 �ִٸ� ���� Ʈ���� ��Ʈ ��� ��븦 ������ �Ѵ�.

    // ���⼭ �� �� �ִ� ������ ������ ���� ���� �ڽ� ��尡 �־ �׳� �Ѿ��
    // ���� ��忡�� ���� ������ ���� �ʳ�? ��� ������ ���.
    // �׸��� �� ��� ���� ���� ���� ���� ���� �Ǿ��ִ� ��븦 �켱���� ������
    // �� ��븦 �������� �ڽ� ������ �������� ����� �� ���� ���� ��븦 ���� �� �ִ� ����� �ƴұ�? ��� ������ ���.
    // ������ ������ �غ���, ���� ������� ����� ��Ȳ���� ���� Ʈ���� ��Ʈ ��尡 ������ ���� ���� ��Ȳ�� ��,
    // �� ���� Ʈ���� �Ųٷ� ��Ʈ ��带 ������ �ڽ� ��븦 ����� ������ ������ ����� ���� �� ��������.
    // �ֳ��ϸ� �̷��� ����ϸ� �ᱹ ���� ��带 ������ �ȴ�. �׷��� �տ��� ���ߵ��� ���� ��庸�� ������ ���� �� ��븦 ������ ����
    // � ��Ȳ������ ���� ���� ��븦 ������ ����� �ȴ�.
    // ���� ���� ���� �� ������ ������ ���� ���� ���� ���� ������ ���� �� �ִ� ��� ������,
    // �߿��� ���� ���� ���� ���� �� ���� ������ ���� ���� �� ��븦 ������ ���� ������ ���� ����̶�� ���̴�.
    // �� ����� �ݷʸ� ã�ƺ��� �ٸ� ��븦 �������� ����� ���÷� ���� �ᱹ ���� ���� �����ų� ���� ���� ������ �ȴ�.

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

���_END
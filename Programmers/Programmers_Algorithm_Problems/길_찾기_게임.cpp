#include "길_찾기_게임.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

길_찾기_게임_BEGIN

struct Node {
    int num = -1;
    int x;
    int y;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int num, int x, int y)
        : num(num), x(x), y(y) {}
    Node() {}
};

void insertTree(Node* node, Node** parent) {
    
    if ((*parent)->num < 0) {
        *parent = node;
        return;
    }

    if (node->x < (*parent)->x) {
        if ((*parent)->left == nullptr)
            (*parent)->left = node;
        else
            insertTree(node, &(*parent)->left);
    }
    else {
        if ((*parent)->right == nullptr)
            (*parent)->right = node;
        else
            insertTree(node, &(*parent)->right);
    }
}

void traversalPreOrder(Node* parent, vector<vector<int>>& answer) {
    
    if (parent == nullptr)
        return;
    
    answer[0].push_back(parent->num);

    traversalPreOrder(parent->left, answer);
    traversalPreOrder(parent->right, answer);
}

void traversalPostOrder(Node* parent, vector<vector<int>>& answer) {

    if (parent == nullptr)
        return;

    traversalPostOrder(parent->left, answer);
    traversalPostOrder(parent->right, answer);

    answer[1].push_back(parent->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    
    // nodeinfo를 순회해서 각 노드의 정보를 y를 기준으로 나눠서 map으로 저장했다.
    // y는 트리의 높이다.
    // y가 큰 노드들부터 tree에 삽입하면 높이를 계산할 필요 없이 x 값만 참고해서
    // 삽입하면 된다.
    // tree를 만들고 순회했다.

    vector<vector<int>> answer(2);
    
    map<int, vector<vector<int>>> nodesByY;

    Node* root = new Node();

    for (int i = 0; i < nodeinfo.size(); i++) {
        nodeinfo[i].push_back(i + 1);
        nodesByY[-nodeinfo[i][1]].push_back(nodeinfo[i]);
    }

    for (auto nodes : nodesByY) {

        for (vector<int> nodeInform : nodes.second) {
            Node* node = new Node(nodeInform[2], nodeInform[0], nodeInform[1]);
            insertTree(node, &root);
        }
    }

    traversalPreOrder(root, answer);
    traversalPostOrder(root, answer);

    return answer;
}

void service() {

    vector<vector<int>> infos = { {5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2} };

    vector<vector<int>> ans = solution(infos);
    for (auto a : ans) {
        for (auto b : a) {
            cout << b << " ";
        }
        cout << endl;
    }
    cout << endl;
}

길_찾기_게임_END
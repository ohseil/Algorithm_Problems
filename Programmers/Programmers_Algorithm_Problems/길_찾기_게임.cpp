#include "��_ã��_����.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

��_ã��_����_BEGIN

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
    
    // nodeinfo�� ��ȸ�ؼ� �� ����� ������ y�� �������� ������ map���� �����ߴ�.
    // y�� Ʈ���� ���̴�.
    // y�� ū ������� tree�� �����ϸ� ���̸� ����� �ʿ� ���� x ���� �����ؼ�
    // �����ϸ� �ȴ�.
    // tree�� ����� ��ȸ�ߴ�.

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

��_ã��_����_END
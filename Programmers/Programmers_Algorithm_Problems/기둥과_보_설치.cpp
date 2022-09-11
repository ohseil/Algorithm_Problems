#include "��հ�_��_��ġ.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

��հ�_��_��ġ_BEGIN

bool cmp(vector<int> lhs, vector<int> rhs) {
    if (lhs[0] < rhs[0])
        return true;
    else if (lhs[0] == rhs[0])
        if (lhs[1] < rhs[1])
            return true;
        else if (lhs[1] == rhs[1])
            if (lhs[2] == 0)
                return true;
    return false;
}

bool canBuildColumn(vector<vector<vector<int>>>& boards, int x, int y) {
    if (y == 0) return true;
    if (boards[0][y - 1][x] == 0) return true;
    if (boards[1][y][x] == 0) return true;
    if (x - 1 >= 0 && boards[1][y][x - 1] == 0) return true;
    return false;
}

bool canBuildBeam(vector<vector<vector<int>>>& boards, int x, int y) {
    if (boards[0][y - 1][x] == 0) return true;
    if (boards[0][y - 1][x + 1] == 0) return true;
    if (x - 1 >= 0 && boards[1][y][x - 1] == 0 && boards[1][y][x + 1] == 0) return true;
    return false;
}

void buildFrame(vector<vector<vector<int>>>& boards, int x, int y, int type) {
    if (type == 0) {
        if (canBuildColumn(boards, x, y) == true)
            boards[0][y][x] = 0;
    }
    else {
        if (canBuildBeam(boards, x, y) == true)
            boards[1][y][x] = 0;
    }
}

bool canFramesMaintain(vector<vector<vector<int>>>& boards, int size) {
    
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {

            if (boards[0][y][x] == 0) {
                if (canBuildColumn(boards, x, y) == false)
                    return false;
            }
            if (boards[1][y][x] == 0) {
                if (canBuildBeam(boards, x, y) == false)
                    return false;
            }

        }
    }

    return true;
}

void destroyFrame(vector<vector<vector<int>>>& boards, int x, int y, int type, int size) {

    boards[type][y][x] = -1;

    if (canFramesMaintain(boards, size) == false)
        boards[type][y][x] = 0;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {

    // ��� ��ġ ������ ���� ����� �� ��ġ ������ ���� ���� 2���� ����Ѵ�.

    // < ��ġ >
    // ��� ����
    // 1. �ٴ� ���� ��ġ ����
    // 2. ���� ���� �� �κ� ���� ��ġ ����
    // 3. �ٸ� ��� ���� ��ġ ����

    // �� ����
    // 1. ���� �� �κ��� ��� ���� �ִ� ���·� ��ġ ����.
    // 2. ���� �� �κ��� �ٸ� ���� ����Ǿ� �ִ� ���·� ��ġ ����.

    // < ���� ���� >
    // 1. ����
    // 2. board�� ��� ��ǥ�� �˻��ؼ� frame�� �ִ� ��� ���� �˻�
    // 3. ���� ���� ��� frame�� ������ �������� �ʴ´ٸ� ������ frame ����

    // ��� �۾� �� board�� ��� ��ǥ �˻��ؼ� answer �迭�� �����ϰ�,
    // ���ǿ� �°� �����Ѵ�.

    vector<vector<int>> answer;
    vector<vector<vector<int>>> boards(2);

    for (int i = 0; i < 2; i++)
        boards[i] = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));

    for (vector<int> build : build_frame) {

        int x = build[0];
        int y = build[1];
        int type = build[2];
        int work = build[3];

        if (work == 0)
            destroyFrame(boards, x, y, type, n + 1);
        else
            buildFrame(boards, x, y, type);
    }

    for (int y = 0; y < n + 1; y++) {
        for (int x = 0; x < n + 1; x++) {
            if (boards[0][y][x] == 0)
                answer.push_back({ x, y, 0 });
            if (boards[1][y][x] == 0)
                answer.push_back({ x, y, 1 });
        }
    }

    sort(answer.begin(), answer.end(), cmp);

    return answer;
}

void service() {

    int n = 5;
    vector<vector<int>> bframe = { {0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},
        {3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1} };

    vector<vector<int>> ans = solution(n, bframe);
    for (auto a : ans) {
        for (auto b : a)
            cout << b << " ";
        cout << endl;
    }
    cout << endl;
}

��հ�_��_��ġ_END
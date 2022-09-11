#include "기둥과_보_설치.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

기둥과_보_설치_BEGIN

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

    // 기둥 설치 정보를 위한 벽면과 보 설치 정보를 위한 벽면 2개를 사용한다.

    // < 설치 >
    // 기둥 조건
    // 1. 바닥 위에 설치 가능
    // 2. 보의 한쪽 끝 부분 위에 설치 가능
    // 3. 다른 기둥 위에 설치 가능

    // 보 조건
    // 1. 한쪽 끝 부분이 기둥 위에 있는 형태로 설치 가능.
    // 2. 양쪽 끝 부분이 다른 보와 연결되어 있는 형태로 설치 가능.

    // < 삭제 과정 >
    // 1. 삭제
    // 2. board의 모든 좌표를 검사해서 frame이 있는 경우 조건 검사
    // 3. 삭제 후의 모든 frame이 조건을 만족하지 않는다면 삭제된 frame 복구

    // 모든 작업 후 board의 모든 좌표 검사해서 answer 배열에 삽입하고,
    // 조건에 맞게 정렬한다.

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

기둥과_보_설치_END
#include "빛의_경로_사이클.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

빛의_경로_사이클_BEGIN

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

int maxR, maxC;

vector<vector<vector<int>>> validations;

class Node {
public:
    int r;
    int c;
    int fromDirection;
    Node(int r, int c, int d) : r(r), c(c), fromDirection(d) {}
};

int findNextDirection(int fromDirection, char flag) {
    if (flag == 'S') return fromDirection;
    else if (flag == 'L') {
        if (fromDirection == 0) return 3;
        if (fromDirection == 1) return 2;
        if (fromDirection == 2) return 0;
        if (fromDirection == 3) return 1;
    }
    else if (flag == 'R') {
        if (fromDirection == 0) return 2;
        if (fromDirection == 1) return 3;
        if (fromDirection == 2) return 1;
        if (fromDirection == 3) return 0;
    }
}

int moveR(int r, int direction) {
    int nr = r + dr[direction];
    if (nr < 0) return (nr + maxR);
    return nr % maxR;
}
int moveC(int c, int direction) {
    int nc = c + dc[direction];
    if (nc < 0) return (nc + maxC);
    return nc % maxC;
}

int searchRoute(int startR, int startC, int startD, vector<string>& grid) {

    int cycleSize = 0;

    Node node(startR, startC, startD);

    while (validations[node.r][node.c][node.fromDirection] == 0) {

        validations[node.r][node.c][node.fromDirection] = 1;
        cycleSize++;

        int direction = findNextDirection(node.fromDirection, grid[node.r][node.c]);

        int nr = moveR(node.r, direction);
        int nc = moveC(node.c, direction);

        Node nextNode(nr, nc, direction);
        node = nextNode;
    }

    return cycleSize;
}

vector<int> solution(vector<string> grid) {
    
    // 각 노드마다 4가지 방향으로부터 들어올 수 있다.
    // 노드의 위치와 이 4가지 경우로 루트를 구분한다.
    // 모든 노드를 기준으로 4가지 시작루트로 시작해서 사이클을 탐색한다.
    
    // 모든 시작 루트를 기준으로 무조건 사이클이 존재한다.
    // 어떤 시작 루트를 기준으로 탐색을 할 때,
    // 경로에 포함되는 노드에 다시 올 수 없다. 왜냐하면 그 노드로 도달할 수 있는 경로는 하나이기 때문.
    // 그리고 grid에 외부 벽이 없기 때문에 만약 어떤 제한도 없다면 무한으로 이동이 가능하다.
    // 그렇다면 무조건 처음 시작 루트에 도착할 수 밖에 없기 때문에 어떤 시작 루트를 기준으로 해도 사이클이 존재한다.

    vector<int> answer;
    
    maxR = grid.size();
    maxC = grid[0].length();

    validations.assign(maxR, vector<vector<int>>(maxC, vector<int>(4, 0)));

    for (int r = 0; r < maxR; r++) {
        for (int c = 0; c < maxC; c++) {
            for (int d = 0; d < 4; d++) {

                int cycleSize = searchRoute(r, c, d, grid);

                if (cycleSize == 0)
                    continue;

                answer.push_back(cycleSize);
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

void service() {

    vector<string> grid = { "SL","LR" };

    vector<int> ans = solution(grid);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

빛의_경로_사이클_END
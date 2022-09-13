#include "블록_이동하기.h"
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

블록_이동하기_BEGIN

int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };

struct Robot {
    int r1, c1, r2, c2;
    int status;
    Robot(int r1, int c1, int r2, int c2, int status) 
        : r1(r1), c1(c1), r2(r2), c2(c2), status(status) {}
};

bool isBoard(int r, int c, int n) {
    return 0 <= r && r <= n && 0 <= c && c <= n;
}

bool canMove(Robot& robot, vector<vector<int>>& board) {
    return board[robot.r1][robot.c1] == 0 &&
        board[robot.r2][robot.c2] == 0;
}

bool canRotate(Robot& robot, int type, vector<vector<int>>& board) {
    
    int r = robot.r1, c = robot.c1;

    if (robot.status == 0) {
        
        switch (type) {

        case 0:
            return board[r - 1][c] == 0 && board[r - 1][c + 1] == 0;
        case 1:
            return board[r + 1][c] == 0 && board[r + 1][c + 1] == 0;
        case 2:
            return board[r - 1][c + 1] == 0 && board[r - 1][c] == 0;
        case 3:
            return board[r + 1][c + 1] == 0 && board[r + 1][c] == 0;

        }
    }
    else {

        switch (type) {

        case 0:
            return board[r][c - 1] == 0 && board[r + 1][c - 1] == 0;
        case 1:
            return board[r][c + 1] == 0 && board[r + 1][c + 1] == 0;
        case 2:
            return board[r + 1][c - 1] == 0 && board[r][c - 1] == 0;
        case 3:
            return board[r + 1][c + 1] == 0 && board[r][c + 1] == 0;

        }
    }
}

void rotate(Robot& robot, int type) {
    
    int r = robot.r1, c = robot.c1;

    if (robot.status == 0) {
        switch (type) {

        case 0:
            robot = Robot(r - 1, c, r, c, 1);
            break;
        case 1:
            robot = Robot(r, c, r + 1, c, 1);
            break;
        case 2:
            robot = Robot(r - 1, c + 1, r, c + 1, 1);
            break;
        case 3:
            robot = Robot(r, c + 1, r + 1, c + 1, 1);
            break;

        }
    }
    else {
        switch (type) {

        case 0:
            robot = Robot(r, c - 1, r, c, 0);
            break;
        case 1:
            robot = Robot(r, c, r, c + 1, 0);
            break;
        case 2:
            robot = Robot(r + 1, c - 1, r + 1, c, 0);
            break;
        case 3:
            robot = Robot(r + 1, c, r + 1, c + 1, 0);
            break;

        }
    }
}

int solution(vector<vector<int>> board) {
    
    // 로봇이 움직일 수 있는 모든 경우를 고려하여
    // bfs를 통해 모든 경로를 탐색한다.

    // 로봇은 크게 2가지 움직임을 수행한다.
    // 1. 이동
    // 2. 회전

    // 로봇은 (r1,c1), (r2,c2) 로 이루어져 있는데
    // 가로 모양일 때는 무조건 왼쪽 바퀴가 r1,c1에 위치하도록 고려하고
    // 세로 모양일 때는 무조건 위쪽 바퀴가 r1,c1에 위치하도록 고려한다.
    // 이유는 계산할 때 일관성을 위해서다.

    // < 이동 >
    // 이동의 경우는 단순히 두 바퀴를 이동시키면 된다.
    // 4가지 방향으로 이동이 가능하다.

    // < 회전 >
    // 회전은 가로에서의 회전과 세로에서의 회전이 있다.
    // 또한 가로 회전이나 세로 회전 내에서도 (r1,c1)을 기준으로 회전과
    // (r2,c2)를 기준으로 회전 2가지가 있고,
    // 바퀴를 기준으로 회전할 때도 90도로 두 방향으로 회전이 가능하다.
    // 이 모든 경우를 고려한다.

    // 회전할 때는 이동과 다르게 회전 경로에 해당하는 위치가 벽인지도 확인해야 한다.

    // 나는 회전을 계산할 때 다음과 같이 계산했다.
    
    // 가로 모양은 (r,c)(r,c+1) 좌표 형태를 가지고, 다음 좌표들로 회전이 가능하다.
    // (r,c)(r,c+1) -> (r-1,c)(r,c)      -- (r-1,c)와 (r-1,c+1)의 벽 여부 확인 필요.
    //              -> (r,c)(r+1,c)      -- (r+1,c)와 (r+1,c+1)의 벽 여부 확인 필요.
    //              -> (r-1,c+1)(r,c+1)  -- (r-1,c+1)와 (r-1,c)의 벽 여부 확인 필요.
    //              -> (r,c+1)(r+1,c+1)  -- (r+1,c+1)와 (r+1,c)의 벽 여부 확인 필요.

    // 세로 모양은 (r,c)(r+1,c) 좌표 형태를 가지고, 다음 좌표들로 회전이 가능하다.
    // (r,c)(r+1,c) -> (r,c-1)(r,c)      -- (r,c-1)와 (r+1,c-1)의 벽 여부 확인 필요.
    //              -> (r,c)(r,c+1)      -- (r,c+1)와 (r+1,c+1)의 벽 여부 확인 필요.
    //              -> (r+1,c-1)(r+1,c)  -- (r+1,c-1)와 (r,c-1)의 벽 여부 확인 필요.
    //              -> (r+1,c)(r+1,c+1)  -- (r+1,c+1)와 (r,c+1)의 벽 여부 확인 필요.

    int answer = 0;
    
    int n = board.size() - 1;

    set<pair<pair<int, int>, pair<int, int>>> visitedPositions;

    queue<pair<Robot, int>> q;
    q.push({ Robot(0, 0, 0, 1, 0), 0 });
    visitedPositions.insert({ {0,0}, {0,1} });

    while (q.empty() == false) {

        Robot robot = q.front().first;
        int cost = q.front().second;
        q.pop();

        if ((robot.r1 == n && robot.c1 == n) ||
            (robot.r2 == n && robot.c2 == n)) {
            answer = cost;
            break;
        }

        // 이동
        for (int d = 0; d < 4; d++) {
            
            Robot next = robot;
            next.r1 += dr[d];
            next.r2 += dr[d];
            next.c1 += dc[d];
            next.c2 += dc[d];

            if (isBoard(next.r1, next.c1, n) == false)
                continue;
            if (isBoard(next.r2, next.c2, n) == false)
                continue;
            if (canMove(next, board) == false)
                continue;
            if (visitedPositions.count({ {next.r1,next.c1}, {next.r2,next.c2} }) > 0)
                continue;

            q.push({ next, cost + 1 });
            visitedPositions.insert({ {next.r1,next.c1}, {next.r2,next.c2} });
        }

        // 회전
        for (int d = 0; d < 4; d++) {

            Robot next = robot;

            rotate(next, d);

            if (isBoard(next.r1, next.c1, n) == false)
                continue;
            if (isBoard(next.r2, next.c2, n) == false)
                continue;
            if (canRotate(robot, d, board) == false)
                continue;
            if (visitedPositions.count({ {next.r1,next.c1}, {next.r2,next.c2} }) > 0)
                continue;

            q.push({ next, cost + 1 });
            visitedPositions.insert({ {next.r1,next.c1}, {next.r2,next.c2} });
        }
    }

    return answer;
}

void service() {

    vector<vector<int>> board = { {0,0,0,1,1},{0,0,0,1,0},{0,1,0,1,1},{1,1,0,0,1},{0,0,0,0,0} };
    cout << solution(board) << endl;
}

블록_이동하기_END
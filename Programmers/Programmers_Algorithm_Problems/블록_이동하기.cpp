#include "���_�̵��ϱ�.h"
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

���_�̵��ϱ�_BEGIN

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
    
    // �κ��� ������ �� �ִ� ��� ��츦 ����Ͽ�
    // bfs�� ���� ��� ��θ� Ž���Ѵ�.

    // �κ��� ũ�� 2���� �������� �����Ѵ�.
    // 1. �̵�
    // 2. ȸ��

    // �κ��� (r1,c1), (r2,c2) �� �̷���� �ִµ�
    // ���� ����� ���� ������ ���� ������ r1,c1�� ��ġ�ϵ��� ����ϰ�
    // ���� ����� ���� ������ ���� ������ r1,c1�� ��ġ�ϵ��� ����Ѵ�.
    // ������ ����� �� �ϰ����� ���ؼ���.

    // < �̵� >
    // �̵��� ���� �ܼ��� �� ������ �̵���Ű�� �ȴ�.
    // 4���� �������� �̵��� �����ϴ�.

    // < ȸ�� >
    // ȸ���� ���ο����� ȸ���� ���ο����� ȸ���� �ִ�.
    // ���� ���� ȸ���̳� ���� ȸ�� �������� (r1,c1)�� �������� ȸ����
    // (r2,c2)�� �������� ȸ�� 2������ �ְ�,
    // ������ �������� ȸ���� ���� 90���� �� �������� ȸ���� �����ϴ�.
    // �� ��� ��츦 ����Ѵ�.

    // ȸ���� ���� �̵��� �ٸ��� ȸ�� ��ο� �ش��ϴ� ��ġ�� �������� Ȯ���ؾ� �Ѵ�.

    // ���� ȸ���� ����� �� ������ ���� ����ߴ�.
    
    // ���� ����� (r,c)(r,c+1) ��ǥ ���¸� ������, ���� ��ǥ��� ȸ���� �����ϴ�.
    // (r,c)(r,c+1) -> (r-1,c)(r,c)      -- (r-1,c)�� (r-1,c+1)�� �� ���� Ȯ�� �ʿ�.
    //              -> (r,c)(r+1,c)      -- (r+1,c)�� (r+1,c+1)�� �� ���� Ȯ�� �ʿ�.
    //              -> (r-1,c+1)(r,c+1)  -- (r-1,c+1)�� (r-1,c)�� �� ���� Ȯ�� �ʿ�.
    //              -> (r,c+1)(r+1,c+1)  -- (r+1,c+1)�� (r+1,c)�� �� ���� Ȯ�� �ʿ�.

    // ���� ����� (r,c)(r+1,c) ��ǥ ���¸� ������, ���� ��ǥ��� ȸ���� �����ϴ�.
    // (r,c)(r+1,c) -> (r,c-1)(r,c)      -- (r,c-1)�� (r+1,c-1)�� �� ���� Ȯ�� �ʿ�.
    //              -> (r,c)(r,c+1)      -- (r,c+1)�� (r+1,c+1)�� �� ���� Ȯ�� �ʿ�.
    //              -> (r+1,c-1)(r+1,c)  -- (r+1,c-1)�� (r,c-1)�� �� ���� Ȯ�� �ʿ�.
    //              -> (r+1,c)(r+1,c+1)  -- (r+1,c+1)�� (r,c+1)�� �� ���� Ȯ�� �ʿ�.

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

        // �̵�
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

        // ȸ��
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

���_�̵��ϱ�_END
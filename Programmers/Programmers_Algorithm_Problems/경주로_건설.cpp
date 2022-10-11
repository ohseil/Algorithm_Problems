#include "경주로_건설.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

경주로_건설_BEGIN

#define MAX_COST 312500
#define STRAIGHT_COST 100
#define CORNER_COST 600

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

struct Route {
    int r;
    int c;
    int direction;
    int cost;
    Route(int r, int c, int direction, int cost)
        : r(r), c(c), direction(direction), cost(cost) {}
};

struct VisitedCondition {
    int direction;
    int cost;
    VisitedCondition(int direction, int cost)
        : direction(direction), cost(cost) {}
};

bool isBoard(int r, int c, int maxR, int maxC) {
    return 0 <= r && r < maxR && 0 <= c && c < maxC;
}

int solution(vector<vector<int>> board) {
    
    int answer = MAX_COST;

    int maxR = board.size();
    int maxC = board[0].size();
    
    vector<vector<vector<int>>> validations(maxR, vector<vector<int>>(maxC, vector<int>(4, MAX_COST)));

    queue<Route> q;
    q.push(Route(0, 0, 0, 0));
    q.push(Route(0, 0, 2, 0));
    validations[0][0][0] = 0;
    validations[0][0][2] = 0;

    while (q.empty() == false) {

        Route route = q.front();
        q.pop();

        if (route.r == maxR - 1 && route.c == maxC - 1) {
            // 목적지 도착
            if (answer > route.cost) {
                answer = route.cost;
                continue;
            }
        }

        for (int d = 0; d < 4; d++) {

            int nr = route.r + dr[d];
            int nc = route.c + dc[d];
            int nextCost = route.cost;

            if (isBoard(nr, nc, maxR, maxC) == false)
                continue;
            if (board[nr][nc] == 1)
                continue;

            if (d == route.direction)
                nextCost += STRAIGHT_COST;
            else
                nextCost += CORNER_COST;

            if (validations[nr][nc][d] <= nextCost)
                continue;

            q.push(Route(nr, nc, d, nextCost));
            validations[nr][nc][d] = nextCost;

        }
    }

    for (int d = 0; d < 4; d++)
        if (validations[maxR - 1][maxC - 1][d] < answer)
            answer = validations[maxR - 1][maxC - 1][d];

    return answer;
}

void service() {

    vector<vector<int>> board = { {0,0,0},{0,0,0},{0,0,0} };

    cout << solution(board) << endl;
}

경주로_건설_END
#include "���ַ�_�Ǽ�.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

���ַ�_�Ǽ�_BEGIN

#define MAX_COST 312500
#define STRAIGHT_COST 100
#define CORNER_COST 500

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

bool isBoard(int r, int c, int maxR, int maxC) {
    return 0 <= r && r < maxR && 0 <= c && c < maxC;
}

void searchRoute(queue<Route>& q, vector<vector<vector<int>>>& costs, int maxR, int maxC, vector<vector<int>>& board) {

    q.push(Route(0, 0, 0, 0));
    q.push(Route(0, 0, 2, 0));
    costs[0][0][0] = 0;
    costs[0][0][2] = 0;

    while (q.empty() == false) {

        Route route = q.front();
        q.pop();

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
                nextCost += (CORNER_COST + STRAIGHT_COST);

            if (costs[nr][nc][d] <= nextCost)
                continue;

            q.push(Route(nr, nc, d, nextCost));
            costs[nr][nc][d] = nextCost;

        }
    }
}

int getMinCost(vector<vector<vector<int>>>& costs, int maxR, int maxC) {
    
    int minCost = MAX_COST;
    
    for (int d = 0; d < 4; d++)
        if (costs[maxR - 1][maxC - 1][d] < minCost)
            minCost = costs[maxR - 1][maxC - 1][d];
    
    return minCost;
}

int solution(vector<vector<int>> board) {

    // bfs�� ��� ��θ� Ž���Ѵ�.
    // �̶�, �⺻���� ��� Ž������ �ٸ��� ������ ����ؾ� �Ѵ�.
    // �� ��ġ�� cost�� ������ ��,
    // ������� ����ؼ� 4���� ���⿡ ���� cost�� �����Ѵ�.
    // ���� ��θ� ������ ��,
    // ���� ����� �ٸ� �������� ������ ���� �ڳʸ� ������ cost�� �߰��Ѵ�.
    // ���� �������� ������ ���� ���� ������ cost���� �߰��Ѵ�.

    int answer = MAX_COST;

    int maxR = board.size();
    int maxC = board[0].size();

    vector<vector<vector<int>>> costs(maxR, vector<vector<int>>(maxC, vector<int>(4, MAX_COST)));
    queue<Route> q;

    searchRoute(q, costs, maxR, maxC, board);
    answer = getMinCost(costs, maxR, maxC);

    return answer;
}

void service() {

    vector<vector<int>> board = { {0,0,0},{0,0,0},{0,0,0} };

    cout << solution(board) << endl;
}

���ַ�_�Ǽ�_END
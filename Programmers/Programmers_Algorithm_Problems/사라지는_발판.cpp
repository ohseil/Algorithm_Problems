#include "사라지는_발판.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

사라지는_발판_BEGIN

int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };

int maxR, maxC;

bool isBoard(int r, int c, int maxR, int maxC) {
    return 0 <= r && r < maxR && 0 <= c && c < maxC;
}

/*
 1. 승리가 앞순서, 패배가 뒷순서
 2. 둘다 승리라면 횟수가 적은거부터
 3. 둘다 패배라면 횟수가 많은거부터
 */
 bool cmp(int lhs, int rhs) {
    if (lhs % 2 != 0 && rhs % 2 == 0)
        return true;
    else if (lhs % 2 != 0 && rhs % 2 != 0) {
        if (lhs < rhs)
            return true;
    }
    else if (lhs % 2 == 0 && rhs % 2 == 0) {
        if (lhs > rhs)
            return true;
    }
    return false;
}

int movePlayer(vector<vector<int>> board, int mr, int mc, int r, int c) {

    if (board[mr][mc] == 0)
        return 0;

    vector<int> totalMoveCounts = { 0 };

    for (int d = 0; d < 4; d++) {

        int nr = mr + dr[d];
        int nc = mc + dc[d];

        if (isBoard(nr, nc, maxR, maxC) == false)
            continue;
        if (board[nr][nc] == 0)
            continue;

        vector<vector<int>> nBoard = board;
        nBoard[mr][mc] = 0;

        int totalMoveCount = movePlayer(nBoard, r, c, nr, nc) + 1;

        totalMoveCounts.push_back(totalMoveCount);
    }

    sort(totalMoveCounts.begin(), totalMoveCounts.end(), cmp);

    return totalMoveCounts[0];

}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    
    // 플레이어는 최대 4가지 방향으로 이동이 가능하다.
    // 각 플레이어는 항상 최적의 방향으로 움직인다.
    // 4가지 방향 중 한가지 방향이라도 승리 경로가 있는 경우 승리 경로로 이동한다.
    // 2가지 이상 승리 경로가 있는 경우 이동 횟수가 가장 적은 경로로 이동한다.
    // 4가지 방향 모두 패배 경로라면, 이동 횟수가 가장 많은 경로로 이동한다.

    // 각 플레이어의 턴에서 어떤 방향으로 이동했을 때의 총 이동 횟수가 짝수면
    // 현재 턴에서 해당 방향으로 이동했을 때 패배라는 의미고, 홀수라면 승리라는 의미다.

    // 간단하게 예를 들면,
    // 처음에 a가 4가지 방향을 모두 확인했을 때, 한가지라도 승리 경로가 있다면,
    // a는 무조건 승리 경로로 이동한다.
    // 왜냐하면 항상 최적으로 이동하고 이길 수 있다면 실수를 하지 않는 한 이긴다고 했기 때문.

    // 따라서 a가 한번 패배 루트로 이동 후 b가 승리 루트로 이동하는 경우 같은 건 고려할 필요가 없다.

    int answer = 0;
    
    maxR = board.size();
    maxC = board[0].size();

    answer = movePlayer(board, aloc[0], aloc[1], bloc[0], bloc[1]);

    return answer;
}

void service() {

    vector<vector<int>> board = { {1,1,1},{1,1,1},{1,1,1} };
    vector<int> aloc = { 1,0 };
    vector<int> bloc = { 1,2 };

    cout << solution(board, aloc, bloc) << endl;
}

사라지는_발판_END
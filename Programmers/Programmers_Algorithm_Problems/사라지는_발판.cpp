#include "�������_����.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

�������_����_BEGIN

int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };

int maxR, maxC;

bool isBoard(int r, int c, int maxR, int maxC) {
    return 0 <= r && r < maxR && 0 <= c && c < maxC;
}

/*
 1. �¸��� �ռ���, �й谡 �޼���
 2. �Ѵ� �¸���� Ƚ���� �����ź���
 3. �Ѵ� �й��� Ƚ���� �����ź���
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
    
    // �÷��̾�� �ִ� 4���� �������� �̵��� �����ϴ�.
    // �� �÷��̾�� �׻� ������ �������� �����δ�.
    // 4���� ���� �� �Ѱ��� �����̶� �¸� ��ΰ� �ִ� ��� �¸� ��η� �̵��Ѵ�.
    // 2���� �̻� �¸� ��ΰ� �ִ� ��� �̵� Ƚ���� ���� ���� ��η� �̵��Ѵ�.
    // 4���� ���� ��� �й� ��ζ��, �̵� Ƚ���� ���� ���� ��η� �̵��Ѵ�.

    // �� �÷��̾��� �Ͽ��� � �������� �̵����� ���� �� �̵� Ƚ���� ¦����
    // ���� �Ͽ��� �ش� �������� �̵����� �� �й��� �ǹ̰�, Ȧ����� �¸���� �ǹ̴�.

    // �����ϰ� ���� ���,
    // ó���� a�� 4���� ������ ��� Ȯ������ ��, �Ѱ����� �¸� ��ΰ� �ִٸ�,
    // a�� ������ �¸� ��η� �̵��Ѵ�.
    // �ֳ��ϸ� �׻� �������� �̵��ϰ� �̱� �� �ִٸ� �Ǽ��� ���� �ʴ� �� �̱�ٰ� �߱� ����.

    // ���� a�� �ѹ� �й� ��Ʈ�� �̵� �� b�� �¸� ��Ʈ�� �̵��ϴ� ��� ���� �� ����� �ʿ䰡 ����.

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

�������_����_END
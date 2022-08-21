#include "파괴되지_않은_건물.h"
#include <iostream>
#include <vector>

using namespace std;

파괴되지_않은_건물_BEGIN

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    
    // 2차원 배열의 prefix sum 알고리즘 사용
    // prefix sum 계산을 위한 2차원 배열 사용
    // 각 스킬마다 직사각형 범위 중 4개의 꼭지점에 파워를 더한다.
    // (r1,c1)과 (r2+1,c2+1) 꼭지점에는 파워를 더하고
    // (r1,c2+1)과 (r2+1, c1) 꼭지점에는 파워를 뺀다.
    // 여기서 파워는 파괴 스킬인 경우에는 음수고 회복 스킬인 경우엔 양수다.

    // 세팅된 prefix board를 2차원 prefix sum 계산을 하게 되면,
    // 각 위치에는 모든 스킬을 적용 후의 결과 값을 확인할 수 있다.

    int answer = 0;
    
    int row = board.size();
    int col = board[0].size();

    vector<vector<int>> prefixBoard(board.size(), vector<int>(board[0].size(), 0));

    for (vector<int> skl : skill) {

        int type = skl[0];
        int r1 = skl[1];
        int c1 = skl[2];
        int r2 = skl[3];
        int c2 = skl[4];
        int power = (type == 1) ? -skl[5] : skl[5];

        prefixBoard[r1][c1] += power;

        if (c2 + 1 < col)
            prefixBoard[r1][c2 + 1] -= power;
        if (r2 + 1 < row)
            prefixBoard[r2 + 1][c1] -= power;
        if (c2 + 1 < col && r2 + 1 < row)
            prefixBoard[r2 + 1][c2 + 1] += power;
    }

    for (int r = 0; r < row; r++)
        for (int c = 1; c < col; c++)
            prefixBoard[r][c] += prefixBoard[r][c - 1];

    for (int c = 0; c < col; c++)
        for (int r = 1; r < row; r++)
            prefixBoard[r][c] += prefixBoard[r - 1][c];

    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++)
            if (board[r][c] + prefixBoard[r][c] > 0)
                answer++;

    return answer;
}

void service() {

    vector<vector<int>> board = { {5,5,5,5,5},
                                  {5,5,5,5,5},
                                  {5,5,5,5,5},
                                  {5,5,5,5,5} };

    vector<vector<int>> skills = { {1,0,0,3,4,4},
                                   {1,2,0,2,3,2},
                                   {2,1,0,3,1,2},
                                   {1,0,1,3,3,1} };

    cout << solution(board, skills) << endl;
}

파괴되지_않은_건물_END
#include "행렬_테두리_회전하기.h"
#include <iostream>
#include <vector>

using namespace std;

행렬_테두리_회전하기_BEGIN

void setBoard(int rows, int columns, vector<vector<int>>& board) {
    for (int r = 1; r <= rows; r++)
        for (int c = 1; c <= columns; c++)
            board[r][c] = ((r - 1) * columns + c);
}

int rotateAndGetMinNum(int r1, int c1, int r2, int c2, vector<vector<int>>& board) {

    int minNum = board[r1][c1];
    int temp = board[r1][c1];

    for (int c = c1 + 1; c <= c2; c++) {
        swap(temp, board[r1][c]);
        minNum = min(minNum, board[r1][c]);
    }
    for (int r = r1 + 1; r <= r2; r++) {
        swap(temp, board[r][c2]);
        minNum = min(minNum, board[r][c2]);
    }
    for (int c = c2 - 1; c >= c1; c--) {
        swap(temp, board[r2][c]);
        minNum = min(minNum, board[r2][c]);
    }
    for (int r = r2 - 1; r >= r1; r--) {
        swap(temp, board[r][c1]);
        minNum = min(minNum, board[r][c1]);
    }

    return minNum;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    
    vector<int> answer;
    
    vector<vector<int>> board(rows + 1, vector<int>(columns + 1));

    setBoard(rows, columns, board);

    for (vector<int> query : queries) {
        
        int r1 = query[0];
        int c1 = query[1];
        int r2 = query[2];
        int c2 = query[3];

        answer.push_back(rotateAndGetMinNum(r1, c1, r2, c2, board));
    }

    return answer;
}

void service() {

    int rows = 6;
    int columns = 6;
    vector<vector<int>> queries = { {2,2,5,4},{3,3,6,6},{5,1,6,3} };

    vector<int> ans = solution(rows, columns, queries);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

행렬_테두리_회전하기_END
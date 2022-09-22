#include "프렌즈4블록.h"
#include <iostream>
#include <vector>
#include <set>

using namespace std;

프렌즈4블록_BEGIN

bool canErase(char b1, char b2, char b3, char b4) {
    return (b1 != '?' && b2 != '?' && b3 != '?' && b4 != '?') 
            && (b1 == b2 && b2 == b3 && b3 == b4);
}

void eraseBlocks(int m, int n, vector<string>& board, set<pair<int, int>>& erasingBlocks) {

    for (int h = 0; h < m - 1; h++) {
        for (int w = 0; w < n - 1; w++) {

            if (canErase(board[h][w], board[h + 1][w], board[h][w + 1], board[h + 1][w + 1]) == true) {
                erasingBlocks.insert({ h, w });
                erasingBlocks.insert({ h + 1, w });
                erasingBlocks.insert({ h, w + 1 });
                erasingBlocks.insert({ h + 1, w + 1 });
            }
        }
    }

    for (pair<int, int> block : erasingBlocks)
        board[block.first][block.second] = '?';
}

void arrangeBlocks(int m, int n, vector<string>& board, set<pair<int, int>>& erasingBlocks) {

    for (int w = 0; w < n; w++) {

        int bottom = m;

        for (int h = m - 1; h >= 0; h--) {
            
            if (board[h][w] == '?')
                break;

            bottom = h;
        }

        for (int h = bottom - 1; h >= 0; h--) {

            if (board[h][w] != '?') {
                board[bottom - 1][w] = board[h][w];
                board[h][w] = '?';
                bottom--;
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    
    // [ 큰 과정 ]
    // 1. board에서 지울 수 있는 블록들을 확인하고 지운다.
    // 2. 지워진 블록이 없다면 종료하고 있다면 3번 과정을 진행한다.
    // 3. 지운 후 빈 공간 위에 있는 블록들을 밑으로 내리는 정렬 과정을 진행한다.
    //    그리고 1번 과정부터 다시 진행한다.

    // [ 지우는 방법 ]
    // board의 모든 블럭을 탐색하는데 2x2 범위씩 탐색한다.
    // set을 사용해서 탐색하면서 set에 지울 block의 좌표를 넣는다.
    // set을 사용하면 중복을 피할 수 있기 때문에 겹치는 block 중복을 피할 수 있다.

    int answer = 0;
    
    set<pair<int, int>> erasingBlocks;

    while (true) {

        eraseBlocks(m, n, board, erasingBlocks);

        if (erasingBlocks.empty() == true)
            break;

        answer += erasingBlocks.size();

        arrangeBlocks(m, n, board, erasingBlocks);

        erasingBlocks.clear();
    }

    return answer;
}

void service() {

    int m = 4;
    int n = 5;
    vector<string> board = { "CCBDE", "AAADE", "AAABF", "CCBBF" };

    cout << solution(m, n, board);
}

프렌즈4블록_END
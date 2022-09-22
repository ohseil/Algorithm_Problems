#include "������4���.h"
#include <iostream>
#include <vector>
#include <set>

using namespace std;

������4���_BEGIN

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
    
    // [ ū ���� ]
    // 1. board���� ���� �� �ִ� ��ϵ��� Ȯ���ϰ� �����.
    // 2. ������ ����� ���ٸ� �����ϰ� �ִٸ� 3�� ������ �����Ѵ�.
    // 3. ���� �� �� ���� ���� �ִ� ��ϵ��� ������ ������ ���� ������ �����Ѵ�.
    //    �׸��� 1�� �������� �ٽ� �����Ѵ�.

    // [ ����� ��� ]
    // board�� ��� ���� Ž���ϴµ� 2x2 ������ Ž���Ѵ�.
    // set�� ����ؼ� Ž���ϸ鼭 set�� ���� block�� ��ǥ�� �ִ´�.
    // set�� ����ϸ� �ߺ��� ���� �� �ֱ� ������ ��ġ�� block �ߺ��� ���� �� �ִ�.

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

������4���_END
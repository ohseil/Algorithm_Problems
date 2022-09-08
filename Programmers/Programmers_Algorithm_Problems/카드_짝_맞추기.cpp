#include "ī��_¦_���߱�.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

ī��_¦_���߱�_BEGIN

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

bool isBoard(int r, int c, int maxR, int maxC) {
    return 0 <= r && r < maxR && 0 <= c && c < maxC;
}

void findCard(vector<vector<int>>& board, pair<int, int> cardPos, int& r, int& c, int& moveCount) {

    int maxR = board.size();
    int maxC = board[0].size();

    queue<pair<int, int>> q;
    q.push({ r, c });

    for (int move = 0; move < 16; move++) {

        int qsize = q.size();
        bool isCard = false;

        for (int qi = 0; qi < qsize; qi++) {

            pair<int, int> curPos = q.front();
            q.pop();

            if (curPos.first == cardPos.first && curPos.second == cardPos.second) {
                moveCount += (move + 1); // enter���� ���� Ƚ�� 1 �߰�.
                r = cardPos.first;
                c = cardPos.second;
                isCard = true;
                break;
            }

            // 4���� ���� �̵� �� Ctrl �̵�
            for (int d = 0; d < 4; d++) {

                int nr = curPos.first + dr[d];
                int nc = curPos.second + dc[d];

                if (isBoard(nr, nc, maxR, maxC) == false)
                    continue;

                q.push({ nr, nc });

                bool isMoved = false;

                while (isBoard(nr, nc, maxR, maxC) == true) {

                    if (board[nr][nc] != 0) {
                        isMoved = true;
                        break;
                    }

                    nr += dr[d];
                    nc += dc[d];
                }

                if (isMoved == false) {
                    nr -= dr[d];
                    nc -= dc[d];
                }

                q.push({ nr, nc });
            }
        }

        if (isCard == true)
            break;
    }
}

void startGame(vector<vector<int>> board, vector<pair<int, int>>& order, int& answer, int r, int c) {

    int moveCount = 0;

    for (int i = 0; i < order.size(); i += 2) {

        pair<int, int> firstCardPos = order[i];
        pair<int, int> secondCardPos = order[i + 1];

        findCard(board, firstCardPos, r, c, moveCount);
        findCard(board, secondCardPos, r, c, moveCount);

        board[firstCardPos.first][firstCardPos.second] = 0;
        board[secondCardPos.first][secondCardPos.second] = 0;
    }

    if (moveCount < answer)
        answer = moveCount;
}

void innerPermutation(vector<vector<pair<int, int>>>& orders, vector<int> cards, vector<bool> validations, int depth, vector<vector<int>>& cardPositions) {
    
    
    if (depth == cards.size()) {

        vector<pair<int, int>> order;

        for (int i = 0; i < cards.size(); i++) {

            int card = cards[i];
            vector<int> cardPos = cardPositions[card];
            bool validation = validations[i];
            
            if (validation == false) {
                order.emplace_back(cardPos[0], cardPos[1]);
                order.emplace_back(cardPos[2], cardPos[3]);
            }
            else {
                order.emplace_back(cardPos[2], cardPos[3]);
                order.emplace_back(cardPos[0], cardPos[1]);
            }
        }

        orders.push_back(order);

        return;
    }
    
    vector<bool> nextValidations = validations;
    nextValidations.push_back(false);
    innerPermutation(orders, cards, nextValidations, depth + 1, cardPositions);
    nextValidations = validations;
    nextValidations.push_back(true);
    innerPermutation(orders, cards, nextValidations, depth + 1, cardPositions);
}

void outerPermutation(vector<vector<pair<int, int>>>& orders, vector<int> cards, int depth, vector<vector<int>>& cardPositions) {

    if (depth == cards.size()) {
        innerPermutation(orders, cards, vector<bool>(), 0, cardPositions);
        return;
    }  

    for (int i = depth; i < cards.size(); i++) {
        swap(cards[depth], cards[i]);
        outerPermutation(orders, cards, depth + 1, cardPositions);
        swap(cards[depth], cards[i]);
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    
    // board�� �����ִ� ī���� ��� ������ ����Ѵ�.
    
    // ���� ��ȣ�� �ٸ� ī���� ��� ������ Ž���ϰ�,
    // ���� ��ȣ�� ���� 2���� ī�� ������ �ٲٴ� ��쵵 ����ؼ� ��� ������ Ž���Ѵ�.

    // �� ��츶�� ������ �����Ѵ�.
    // ���� ������ ������ ����.
    // 1. ù ��° ī�� Ž��.
    // 2. �ι�° ī�� Ž��.
    // 3. ���� 2���� ī�� board���� ���ֱ�.
    // ���� �Ϸ� ���� ���� Ƚ���� �� �ּڰ��� ã�´�.

    int answer = 100000;
    
    vector<vector<pair<int, int>>> orders;
    vector<int> cards;
    vector<vector<int>> cardPositions(7);

    for (int ri = 0; ri < board.size(); ri++) {
        for (int ci = 0; ci < board[0].size(); ci++) {
            
            if (board[ri][ci] == 0)
                continue;

            bool isCard = false;

            for (int card : cards) {
                if (board[ri][ci] == card) {
                    isCard = true;
                    break;
                }
            }

            if (isCard == false)
                cards.push_back(board[ri][ci]);

            cardPositions[board[ri][ci]].push_back(ri);
            cardPositions[board[ri][ci]].push_back(ci);
        }
    }

    sort(cards.begin(), cards.end());

    outerPermutation(orders, cards, 0, cardPositions);
    
    for (vector<pair<int, int>> order : orders)
        startGame(board, order, answer, r, c);

    return answer;
}

void service() {

    vector<vector<int>> board = { {1,0,0,3},{2,0,0,0},{0,0,0,2},{3,0,1,0} };
    int r = 1;
    int c = 0;

    cout << solution(board, r, c) << endl;
}

ī��_¦_���߱�_END
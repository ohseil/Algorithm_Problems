#include "자물쇠와_열쇠.h"
#include <iostream>
#include <vector>

using namespace std;

자물쇠와_열쇠_BEGIN

void rotateKey(vector<vector<int>>& key) {

    vector<vector<int>> rotatedKey(key.size(), vector<int>(key.size()));

    for (int r = 0; r < key.size(); r++) {
        for (int c = 0; c < key.size(); c++) {
            rotatedKey[c][key.size() - 1 - r] = key[r][c];
        }
    }

    key = rotatedKey;
}

bool isUnlock(vector<vector<int>>& lockBoard, vector<vector<int>>& keyBoard, int m, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (lockBoard[r + m - 1][c + m - 1] == keyBoard[r + m - 1][c + m - 1]) {
                return false;
            }
        }
    }
    return true;
}

void setKeyBoard(vector<vector<int>>& keyBoard, vector<vector<int>>& key, int startR, int startC, int m) {
    for (int r = startR; r < (startR + m); r++) {
        for (int c = startC; c < (startC + m); c++) {
            keyBoard[r][c] = key[r - startR][c - startC];
        }
    }
}

void setLockBoard(vector<vector<int>>& lockBoard, vector<vector<int>>& lock, int m, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            lockBoard[r + m - 1][c + m - 1] = lock[r][c];
        }
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

    // 크게 2가지 과정으로 진행된다.
    // 1. key로 lock 해제 시도
    // 2. key 회전

    // key로 lock을 해제해보는 과정은 다음과 같은 방법으로 진행했다.
    // key로 lock을 해제할 수 있는지 알기 위해서는 모든 겹치는 경우를 확인해야 한다.
    // lock을 아래에 두고 key의 가장 오른쪽 아래 칸과 lock의 가장 왼쪽 윗칸을 겹치는 경우부터 시작한다.
    // key를 한 칸씩 옮기면서 모든 겹치는 경우를 탐색한다.
    // 이를 쉽게 하기 위해서 따로 같은 크기의 lockBoard와 keyBoard를 만든다.
    // 이 board의 크기는 key로 겹치게 할 수 있는 모든 경우를 고려할 때 총 범위로 잡는다.
    // 결국 lockBoard는 lock에서 좌,우,위,아래로 m - 1만큼의 padding이 생긴 board다.
    // board의 한 변의 길이는 (n + m * 2 - 2)가 된다.
    // keyBoard에서 key 데이터는 0,0부터 한 칸씩 이동하면서 lockBoard에서의 lock 범위의 데이터와 비교한다.

    bool answer = false;

    int m = key.size();
    int n = lock.size();
    int size = lock.size() + key.size() * 2 - 2;

    vector<vector<int>> lockBoard(size, vector<int>(size, 0));

    setLockBoard(lockBoard, lock, m, n);

    for (int i = 0; i < 4; i++) {

        for (int sr = 0; sr < (size - m + 1); sr++) {
            for (int sc = 0; sc < (size - m + 1); sc++) {

                vector<vector<int>> keyBoard(size, vector<int>(size, 0));

                setKeyBoard(keyBoard, key, sr, sc, m);

                if (isUnlock(lockBoard, keyBoard, m, n) == true)
                    return true;
            }
        }

        rotateKey(key);
    }

    return answer;
}

void service() {

    vector<vector<int>> key = { {0,0,0},{1,0,0},{0,1,1} };
    vector<vector<int>> lock = { {1,1,1},{1,1,0},{1,0,1} };

    cout << solution(key, lock) << endl;
}

자물쇠와_열쇠_END
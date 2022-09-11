#include "�ڹ����_����.h"
#include <iostream>
#include <vector>

using namespace std;

�ڹ����_����_BEGIN

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

    // ũ�� 2���� �������� ����ȴ�.
    // 1. key�� lock ���� �õ�
    // 2. key ȸ��

    // key�� lock�� �����غ��� ������ ������ ���� ������� �����ߴ�.
    // key�� lock�� ������ �� �ִ��� �˱� ���ؼ��� ��� ��ġ�� ��츦 Ȯ���ؾ� �Ѵ�.
    // lock�� �Ʒ��� �ΰ� key�� ���� ������ �Ʒ� ĭ�� lock�� ���� ���� ��ĭ�� ��ġ�� ������ �����Ѵ�.
    // key�� �� ĭ�� �ű�鼭 ��� ��ġ�� ��츦 Ž���Ѵ�.
    // �̸� ���� �ϱ� ���ؼ� ���� ���� ũ���� lockBoard�� keyBoard�� �����.
    // �� board�� ũ��� key�� ��ġ�� �� �� �ִ� ��� ��츦 ����� �� �� ������ ��´�.
    // �ᱹ lockBoard�� lock���� ��,��,��,�Ʒ��� m - 1��ŭ�� padding�� ���� board��.
    // board�� �� ���� ���̴� (n + m * 2 - 2)�� �ȴ�.
    // keyBoard���� key �����ʹ� 0,0���� �� ĭ�� �̵��ϸ鼭 lockBoard������ lock ������ �����Ϳ� ���Ѵ�.

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

�ڹ����_����_END
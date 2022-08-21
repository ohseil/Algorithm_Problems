#include "�ı�����_����_�ǹ�.h"
#include <iostream>
#include <vector>

using namespace std;

�ı�����_����_�ǹ�_BEGIN

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    
    // 2���� �迭�� prefix sum �˰��� ���
    // prefix sum ����� ���� 2���� �迭 ���
    // �� ��ų���� ���簢�� ���� �� 4���� �������� �Ŀ��� ���Ѵ�.
    // (r1,c1)�� (r2+1,c2+1) ���������� �Ŀ��� ���ϰ�
    // (r1,c2+1)�� (r2+1, c1) ���������� �Ŀ��� ����.
    // ���⼭ �Ŀ��� �ı� ��ų�� ��쿡�� ������ ȸ�� ��ų�� ��쿣 �����.

    // ���õ� prefix board�� 2���� prefix sum ����� �ϰ� �Ǹ�,
    // �� ��ġ���� ��� ��ų�� ���� ���� ��� ���� Ȯ���� �� �ִ�.

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

�ı�����_����_�ǹ�_END
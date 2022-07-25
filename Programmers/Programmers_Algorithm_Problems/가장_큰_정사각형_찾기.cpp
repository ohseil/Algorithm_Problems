#include "����_ū_���簢��_ã��.h"
#include <iostream>
#include <vector>

using namespace std;

����_ū_���簢��_ã��_BEGIN

void setPrefixSum(vector<vector<int>>& before, vector<vector<int>>& after) {

    int max_r = after.size();
    int max_c = after[0].size();

    for (int r = 1; r < max_r; r++)
        for (int c = 1; c < max_c; c++)
            after[r][c] = after[r][c - 1] + before[r - 1][c - 1];

    for (int r = 1; r < max_r; r++)
        for (int c = 1; c < max_c; c++)
            after[r][c] += after[r - 1][c];
}

int solution(vector<vector<int>> board)
{
    // prefix sum�� ����ߴ�.
    // ���� �� row���� prefix sum�� ���Ѵ�.
    // �� �� ���� 2���� �迭���� �ٽ� �ѹ� col���� prefix sum�� ���Ѵ�.
    // �̷��� ���� 2���� �迭���� (r,c)���� ���̰� len�� ���簢���� 1�� ���� ������
    // v[r][c] - v[r-len][c] - v[r][c-len] + v[r-len][c-len]�� �ȴ�.

    // �� ��ǥ���� �ش� ������ �̿��ؼ� ���̰� 1�� ���簢������ ������ �������� Ȯ���Ѵ�.
    // �̶�, ������ ���ߴ� �ִ� ���簢���� �Ѻ��� ���̸� ������ ����
    // ���� ������ �� ���̺��� ū ���� ���� ���簢������ ���ؼ� �ߺ� ����� �����Ѵ�.

    int answer = 0;
    int start_len = 1;

    vector<vector<int>> pre_sum_v(board.size() + 1, vector<int>(board[0].size() + 1, 0));

    int max_r = pre_sum_v.size();
    int max_c = pre_sum_v[0].size();

    setPrefixSum(board, pre_sum_v);

    for (int r = 1; r < max_r; r++) {
        for (int c = 1; c < max_c; c++) {
        
            int min_len = min(r, c);

            for (int len = start_len; len <= min_len; len++) {
             
                int one_count = pre_sum_v[r][c] - pre_sum_v[r - len][c] - pre_sum_v[r][c - len] + pre_sum_v[r - len][c - len];

                if (one_count != len * len)
                    break;

                if (one_count > answer) {
                    answer = one_count;
                    start_len = len + 1;
                }
            }
        }
    }

    return answer;
}

void service() {

    vector<vector<int>> b = { {0,0,1,1},{1,1,1,1} };//{ {0,1,1,1},{1,1,1,1},{1,1,1,1},{0,0,1,0} };
    cout << solution(b) << endl;
}

����_ū_���簢��_ã��_END
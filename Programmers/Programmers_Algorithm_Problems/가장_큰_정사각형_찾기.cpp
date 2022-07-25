#include "가장_큰_정사각형_찾기.h"
#include <iostream>
#include <vector>

using namespace std;

가장_큰_정사각형_찾기_BEGIN

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
    // prefix sum을 사용했다.
    // 먼저 각 row마다 prefix sum을 구한다.
    // 그 후 구한 2차원 배열에서 다시 한번 col마다 prefix sum을 구한다.
    // 이렇게 구한 2차원 배열에서 (r,c)에서 길이가 len인 정사각형의 1의 개수 공식은
    // v[r][c] - v[r-len][c] - v[r][c-len] + v[r-len][c-len]이 된다.

    // 각 좌표에서 해당 공식을 이용해서 길이가 1인 정사각형부터 가능한 범위까지 확인한다.
    // 이때, 이전에 구했던 최대 정사각형의 한변의 길이를 저장해 놓고
    // 다음 점부터 이 길이보다 큰 변을 가진 정사각형부터 구해서 중복 계산을 제거한다.

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

가장_큰_정사각형_찾기_END
#include "공_이동_시뮬레이션.h"
#include <iostream>
#include <vector>

using namespace std;

공_이동_시뮬레이션_BEGIN

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    
    // 도착 지점을 기준으로 역으로 query를 실행하여 계산한다.
    // 가능한 위치의 범위는 무조건 직사각형 형태이다.
    
    // 왼쪽 이동 쿼리를 계산하는 경우를 예로 들면,
    // 현재 지점이 벽에 붙어있지 않은 경우와
    // 벽에 붙어있는 경우 2가지로 나눠서 생각할 수 있다.

    // 벽에 붙어있지 않은 경우에는
    // 무조건 이동 거리만큼 오른쪽으로 이동한 범위가 된다.
    // 하지만 이때 범위가 벽을 벗어나는 경우에는 이 문제를 해결할 수 없는 것으로 판단한다.

    // 벽에 붙어있는 경우에는
    // 벽과 반대되는 행이나 열부터 이동 거리만큼 늘인 범위가 된다.
    // 벽에 붙어있으면 이동 거리보다 적게 떨어진 범위는 무조건 이동할 수 있기 때문이다.

    long long answer = -1;

    long long x1, y1, x2, y2;

    x1 = x2 = x;
    y1 = y2 = y;


    for (int i = queries.size() - 1; i >= 0; i--) {

        int movement = queries[i][0];
        int value = queries[i][1];

        if (movement == 0) {
            // 왼쪽 이동
            if (y1 == 0) {
                // 벽에 붙은 경우
                y2 = (y2 + value >= m) ? (m - 1) : y2 + value;
            }
            else {
                
                if (y1 + value >= m) {
                    answer = 0;
                    return answer;
                }

                y1 += value;
                y2 = (y2 + value >= m) ? (m - 1) : y2 + value;

            }
        }
        else if (movement == 1) {
            // 오른쪽 이동
            if (y2 == m - 1) {
                // 벽에 붙은 경우
                y1 = (y1 - value < 0) ? 0 : y1 - value;
            }
            else {

                if (y2 - value < 0) {
                    answer = 0;
                    return answer;
                }

                y2 -= value;
                y1 = (y1 - value < 0) ? 0 : y1 - value;

            }
        }
        else if (movement == 2) {
            // 위쪽 이동
            if (x1 == 0) {
                // 벽에 붙은 경우
                x2 = (x2 + value >= n) ? (n - 1) : x2 + value;
            }
            else {

                if (x1 + value >= n) {
                    answer = 0;
                    return answer;
                }

                x1 += value;
                x2 = (x2 + value >= n) ? (n - 1) : x2 + value;

            }
        }
        else if (movement == 3) {
            // 아래쪽 이동
            if (x2 == n - 1) {
                // 벽에 붙은 경우
                x1 = (x1 - value < 0) ? 0 : x1 - value;
            }
            else {

                if (x2 - value < 0) {
                    answer = 0;
                    return answer;
                }

                x2 -= value;
                x1 = (x1 - value < 0) ? 0 : x1 - value;

            }
        }
    }
    
    answer = (long long)(x2 - x1 + 1) * (y2 - y1 + 1);

    return answer;
}

void service() {

    int n = 2;
    int m = 2;
    int x = 0;
    int y = 0;
    vector<vector<int>> q = { {2,1},{0,1},{1,1},{0,1},{2,1} };
    cout << solution(n, m, x, y, q) << endl;
}

공_이동_시뮬레이션_END
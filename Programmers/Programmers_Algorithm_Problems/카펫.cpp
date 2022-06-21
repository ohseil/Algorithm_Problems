#include "카펫.h"
#include <iostream>
#include <vector>

using namespace std;

카펫_BEGIN

vector<int> solution(int brown, int yellow) {
    
    // 가로 * 2 + 세로 * 2 - 4 = brown개수
    // (가로 + 세로) = (brown개수 + 4) / 2
    // 가로 x 세로 = brown개수 + yellow개수 를 만족하는
    // 가로와 세로를 찾는다.

    vector<int> answer;
    
    int row_col = (brown + 4) / 2;

    for (int row = 1; row <= (row_col / 2); row++) {

        int col = row_col - row;

        if (row * col == brown + yellow) {
            answer = { col, row };
            break;
        }
    }

    return answer;
}

void service() {

    int brown = 24;
    int yellow = 24;
    vector<int> ans = solution(brown, yellow);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

카펫_END
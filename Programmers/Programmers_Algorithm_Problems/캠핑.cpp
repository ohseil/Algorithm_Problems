#include "캠핑.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

캠핑_BEGIN

int solution(int n, vector<vector<int>> data) {
    
    // 쐐기 좌표를 오름차순으로 정렬한다.
    // 그러면 x좌표를 기준으로 정렬하게 된다.

    // 첫 좌표부터 차례대로 2개씩 쐐기를 선택해서 확인한다.
    // 확인 과정은 너비가 0이 아니어야 하고,
    // 직사각형 안에 쐐기가 없어야 한다.

    // 직사각형 안에 쐐기가 없는지 확인하는 범위는
    // 선택된 2개의 쐐기가 i,j라고 했을 때
    // i + 1 ~ j - 1 까지 확인한다.
    // 이유는 x축 기준으로 정렬되어 있기 때문에
    // 직사각형이 만들어 졌다면, i보다 순서가 먼저인 쐐기들은
    // i와 같은 x축에 있거나 i보다 작은 x축에 있기 때문에
    // i,j로 만들어진 직사각형 안에 들어올 수 없다.
    // j보다 큰 쐐기들도 마찬가지 이유로 확인할 필요가 없다.

    int answer = 0;
    
    int len = data.size();

    sort(data.begin(), data.end());

    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {

            int x1 = data[i][0], y1 = data[i][1];
            int x2 = data[j][0], y2 = data[j][1];

            // 직사각형 너비 0
            if (x1 == x2 || y1 == y2)
                continue;

            int min_x, max_x, min_y, max_y;

            min_x = min(x1, x2);
            max_x = max(x1, x2);
            min_y = min(y1, y2);
            max_y = max(y1, y2);

            bool isContained = false;

            for (int k = i + 1; k < j; k++) {

                if (min_x < data[k][0] && data[k][0] < max_x
                    && min_y < data[k][1] && data[k][1] < max_y) {
                    isContained = true;
                    break;
                }
            }

            if (isContained == false)
                answer++;
        }
    }

    return answer;
}

void service() {

    int n = 4;
    vector<vector<int>> d = { {0,0},{1,1},{0,2},{2,0} };
    cout << solution(n, d) << endl;
}

캠핑_END
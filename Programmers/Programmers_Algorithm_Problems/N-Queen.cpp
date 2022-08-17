#include "N-Queen.h"
#include <iostream>
#include <queue>

using namespace std;

NQueen_BEGIN

int solution(int n) {
    
    // 1행부터 n행까지 각 열에 놓을 수 있는 경우를 모두 탐색한다.
    // 이 때, 백트래킹 방식을 사용한다.
    // 놓을 수 없는 경우는 이전 행에서 놓았던 퀸들과 같은 열인 경우와
    // 이전 행에서 놓았던 퀸들 중 하나라도 놓으려는 위치와 대각선에 위치하는 경우다.

    if (n == 1)
        return 1;

    int answer = 0;
    
    queue<vector<pair<int, int>>> q;

    for (int pos = 0; pos < n; pos++) {
        vector<pair<int, int>> v(n, { 0, 0 });
        v[pos].first = 1;
        q.push(v);
    }

    for (int count = 1; count < n; count++) {

        int qsize = q.size();

        for (int qi = 0; qi < qsize; qi++) {

            vector<pair<int, int>> data = q.front();
            q.pop();

            for (int pos = 0; pos < n; pos++) {

                if (data[pos].first == 1)
                    continue;

                bool canPos = true;

                for (int before = 0; before < n; before++) {

                    if (data[before].first == 0)
                        continue;

                    if (before == pos)
                        continue;

                    if (abs(pos - before) == abs(count - data[before].second)) {
                        canPos = false;
                        break;
                    }

                }
                
                if (canPos == true) {
                    vector<pair<int, int>> next = data;
                    next[pos] = { 1, count };
                    q.push(next);
                }
            }

        }
    }

    answer = q.size();

    return answer;
}

void service() {

    int n = 4;
    cout << solution(n) << endl;
}

NQueen_End
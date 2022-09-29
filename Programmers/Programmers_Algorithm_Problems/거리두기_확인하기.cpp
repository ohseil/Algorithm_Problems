#include "거리두기_확인하기.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

거리두기_확인하기_BEGIN

#define maxR 5
#define maxC 5

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

bool isPlace(int r, int c) {
    return 0 <= r && r < maxR && 0 <= c && c < maxC;
}

int checkKeepDistance(vector<string>& place) {

    for (int r = 0; r < maxR; r++) {
        for (int c = 0; c < maxC; c++) {

            if (place[r][c] != 'P')
                continue;

            queue<pair<int, int>> q;
            vector<vector<bool>> visited(maxR, vector<bool>(maxC, false));

            q.push({ r, c });
            visited[r][c] = true;

            for (int i = 0; i < 2; i++) {

                int qsize = q.size();

                for (int qi = 0; qi < qsize; qi++) {

                    pair<int, int> data = q.front();
                    q.pop();

                    for (int d = 0; d < 4; d++) {

                        int nr = data.first + dr[d];
                        int nc = data.second + dc[d];

                        if (isPlace(nr, nc) == false)
                            continue;
                        if (visited[nr][nc] == true)
                            continue;
                        if (place[nr][nc] == 'X')
                            continue;

                        if (place[nr][nc] == 'P')
                            return 0;

                        q.push({ nr, nc });
                    }
                }
            }

        }
    }

    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    
    // bfs를 2칸 이동할때까지만 진행한다.
    // 사람이 있는 칸에 도달하게 되는 경우 거리두기 실패를 의미한다.

    // 다음 칸 이동하는 조건은,
    // 1. place 범위에 포함 되어야 한다.
    // 2. 이미 탐색한 칸이 아니어야 한다.
    // 3. 파티션이 아니어야 한다.

    // 멘헤튼 거리 2 이하만큼 떨어진 사람 있는 칸에 도달한다는 의미는
    // 거리두기 조건을 만족하지 않는다는 의미다.

    vector<int> answer;
    
    for (vector<string> place : places)       
        answer.push_back(checkKeepDistance(place));

    return answer;
}

void service() {

    vector<vector<string>> places = { {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
        {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
        {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
        {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
        {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};

    vector<int> ans = solution(places);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

거리두기_확인하기_END
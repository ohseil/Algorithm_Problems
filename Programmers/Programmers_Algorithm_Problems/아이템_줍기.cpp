#include "아이템_줍기.h"
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

아이템_줍기_BEGIN

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool isContained(vector<int> rec, int x, int y) {
    return rec[0] <= x && x <= rec[2] && rec[1] <= y && y <= rec[3];
}


bool isBorder(vector<int> rec, int x, int y, int nx ,int ny) {
    if (x == nx) {
        if (x == rec[0] || x == rec[2])
            return rec[1] <= y && y <= rec[3] && rec[1] <= ny && ny <= rec[3];
    }
    else if (y == ny) {
        if (y == rec[1] || y == rec[3])
            return rec[0] <= x && x <= rec[2] && rec[0] <= nx && nx <= rec[2];
    }
    return false;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    
    // bfs로 탐색.

    // 다음 경로를 탐색할 때 같은 사각형 위의 테두리이면서
    // 나머지 다른 사각형에 포함 된 경로가 아닌지 확인한다.

    int answer = 0;
    
    queue<pair<int, int>> q;
    set<pair<int, int>> validation_s;

    q.push({ characterX, characterY });
    validation_s.insert({ characterX, characterY });

    while (q.empty() == false) {

        bool isArrived = false;

        int qsize = q.size();

        for (int i = 0; i < qsize; i++) {

            pair<int, int> data = q.front();
            q.pop();

            if (data.first == itemX && data.second == itemY) {
                isArrived = true;
                break;
            }

            for (int d = 0; d < 4; d++) {

                int nx = data.first + dx[d];
                int ny = data.second + dy[d];
            
                if (validation_s.count({ nx, ny }) > 0)
                    continue;

                bool isSameRec = false, isAnotherContained = false;

                for (vector<int> rec : rectangle) {
                    if (isBorder(rec, data.first, data.second, nx, ny) == true) {
                        isSameRec = true;
                    }
                    else if (isContained(rec, data.first, data.second) == true &&
                            isContained(rec, nx, ny) == true) {

                        isAnotherContained = true;
                    }
                }

                if (isSameRec == false || isAnotherContained == true)
                    continue;

                q.push({ nx, ny });
                validation_s.insert({ nx, ny });
            }
        }

        if (isArrived == true)
            break;

        answer++;
    }

    return answer;
}

void service() {

    vector<vector<int>> r = { {2,2,5,5},{1,3,6,4},{3,1,4,6} };
    int cx = 1, cy = 4, ix = 6, iy = 3;
    cout << solution(r, cx, cy, ix, iy) << endl;

}

아이템_줍기_END
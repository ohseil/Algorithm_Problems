#include "Ä«Ä«¿ÀÇÁ·»Áî_ÄÃ·¯¸µºÏ.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

Ä«Ä«¿ÀÇÁ·»Áî_ÄÃ·¯¸µºÏ_BEGIN

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

bool isPictureArea(int r, int c, int maxR, int maxC) {
    return 0 <= r && r < maxR && 0 <= c && c < maxC;
}

int searchColorArea(int startR, int startC, int m, int n, int color, vector<vector<int>>& picture) {

    int size = 0;

    queue<pair<int, int>> q;
    q.push({ startR, startC });
    picture[startR][startC] = 0;
    size++;
    
    while (q.empty() == false) {

        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {

            int nr = r + dr[d];
            int nc = c + dc[d];

            if (isPictureArea(nr, nc, m, n) == false)
                continue;
            if (picture[nr][nc] != color)
                continue;

            q.push({ nr, nc });
            picture[nr][nc] = 0;
            size++;
        }
    }

    return size;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    vector<int> answer(2);
    
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {

            if (picture[r][c] == 0)
                continue;

            int color = picture[r][c];
            int size = searchColorArea(r, c, m, n, color, picture);

            if (size > max_size_of_one_area)
                max_size_of_one_area = size;
            
            number_of_area++;
        }
    }
    
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    return answer;
}

void service() {

    int m = 6;
    int n = 4;
    vector<vector<int>> picture = { {1,1,1,0},{1,2,2,0},{1,0,0,1},{0,0,0,1},{0,0,0,3},{0,0,0,3} };

    vector<int> ans = solution(m, n, picture);
    cout << ans[0] << " " << ans[1] << endl;
}

Ä«Ä«¿ÀÇÁ·»Áî_ÄÃ·¯¸µºÏ_END
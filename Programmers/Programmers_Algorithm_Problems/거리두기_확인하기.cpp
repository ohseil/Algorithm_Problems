#include "�Ÿ��α�_Ȯ���ϱ�.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

�Ÿ��α�_Ȯ���ϱ�_BEGIN

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
    
    // bfs�� 2ĭ �̵��Ҷ������� �����Ѵ�.
    // ����� �ִ� ĭ�� �����ϰ� �Ǵ� ��� �Ÿ��α� ���и� �ǹ��Ѵ�.

    // ���� ĭ �̵��ϴ� ������,
    // 1. place ������ ���� �Ǿ�� �Ѵ�.
    // 2. �̹� Ž���� ĭ�� �ƴϾ�� �Ѵ�.
    // 3. ��Ƽ���� �ƴϾ�� �Ѵ�.

    // ����ư �Ÿ� 2 ���ϸ�ŭ ������ ��� �ִ� ĭ�� �����Ѵٴ� �ǹ̴�
    // �Ÿ��α� ������ �������� �ʴ´ٴ� �ǹ̴�.

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

�Ÿ��α�_Ȯ���ϱ�_END
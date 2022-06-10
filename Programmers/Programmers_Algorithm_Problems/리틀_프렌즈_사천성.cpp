#include "리틀_프렌즈_사천성.h"
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

리틀_프렌즈_사천성_BEGIN

int dm[4] = { 0,0,1,-1 };
int dn[4] = { 1,-1,0,0 };

class node {
public:
    pair<int, int> pos;
    int dv;
    int change_count = 0;
    node(pair<int, int> p, int d) : pos(p), dv(d) {}
};

bool isBoard(int m, int n, int limit_m, int limit_n) {
    return 0 <= m && m < limit_m && 0 <= n && n < limit_n;
}

// BFS
bool checkEraseTile(char tile, vector<string> board, map<char, vector<pair<int, int>>> t_pos_map, int m, int n) {

    pair<int, int> start = t_pos_map[tile][0];
    pair<int, int> end = t_pos_map[tile][1];

    queue<node> q;
    map<vector<int>, int> visited; // key = {m, n, 방향}, value = 방향 변환 횟수

    for (int d = 0; d < 4; d++) {
        q.push(node(start, d));
        visited[{start.first, start.second, d}] = 0;
    }

    while (q.empty() == false) {

        node data = q.front();
        q.pop();

        if (data.pos == end && data.change_count <= 1) {
            return true;
        }

        for (int d = 0; d < 4; d++) {

            int nm = data.pos.first + dm[d];
            int nn = data.pos.second + dn[d];

            node next = data;
            next.pos = { nm, nn };

            if (data.dv != d)
                next.change_count++;

            next.dv = d;

            if (isBoard(nm, nn, m, n) == false)
                continue;
            if (board[nm][nn] != '.' && board[nm][nn] != tile)
                continue;
            // 방향이 2번 이상 꺾이는 경로인 경우
            if (data.change_count == 1 && data.dv != d)
                continue;
            if (visited.count({nm, nn, d}) > 0 && visited[{nm, nn, d}] <= next.change_count)
                continue;

            q.push(next);
            visited[{ nm, nn, d }] = next.change_count;
        }
    }

    return false;
}

string solution(int m, int n, vector<string> board) {
    
    string answer = "IMPOSSIBLE";

    map<char, vector<pair<int, int>>> tile_pos_map; // 타일 위치 맵
    
    set<char> tile_set;
    vector<char> tile_v; // 타일의 알파벳 저장한 vector.
    vector<bool> erased_v; // 각 타일이 지워졌는지에 대한 flag vector.

    for (int mi = 0; mi < m; mi++) {
        for (int ni = 0; ni < n; ni++) {
            char ch = board[mi][ni];
            if ('A' <= ch && ch <= 'Z') {
                tile_set.insert(ch);
                tile_pos_map[ch].push_back({ mi, ni });
            }
        }
    }

    for (char tile : tile_set)
        tile_v.push_back(tile);

    erased_v.assign(tile_v.size(), false);

    string order = "";

    while (true) {

        bool isErased = false;

        for (int i = 0; i < tile_v.size(); i++) {
            if (erased_v[i] == true)
                continue;
            if (checkEraseTile(tile_v[i], board, tile_pos_map, m, n) == true) {
                
                order += tile_v[i];
                erased_v[i] = true;

                for (auto tiles : tile_pos_map[tile_v[i]]) {
                    board[tiles.first][tiles.second] = '.';
                }

                isErased = true;
                break;
            }
        }

        if (isErased == false) {
            break;
        }

        if (order.length() == tile_v.size()) {
            answer = order;
            break;
        }
    }

    return answer;
}

void service() {

    int m = 4;
    int n = 4;
    vector<string> b = { ".ZI.", "M.**", "MZU.", ".IU." };
    cout << solution(m, n, b) << endl;
}

리틀_프렌즈_사천성_END
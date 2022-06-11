#include "게임_맵_최단거리.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

게임_맵_최단거리_BEGIN

#define INF 2100000000

int dn[4] = { 0,0,1,-1 };
int dm[4] = { 1,-1,0,0 };

bool isMap(int n, int m, int max_n, int max_m) {
    return 0 <= n && n <= max_n && 0 <= m && m <= max_m;
}

int solution(vector<vector<int>> maps)
{
    // bfs 탐색

    int answer = -1;
    
    int n = maps.size();
    int m = maps[0].size();

    vector<vector<int>> cost_map(n, vector<int>(m, INF));

    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    cost_map[0][0] = 1;

    while (q.empty() == false) {

        pair<int, int> data = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {

            int nn = data.first + dn[d];
            int nm = data.second + dm[d];

            if (isMap(nn, nm, n - 1, m - 1) == false)
                continue;
            if (maps[nn][nm] == 0)
                continue;
            if (cost_map[nn][nm] <= cost_map[data.first][data.second] + 1)
                continue;

            q.push({ nn, nm });
            cost_map[nn][nm] = cost_map[data.first][data.second] + 1;
        }
    }

    if (cost_map[n - 1][m - 1] != INF)
        answer = cost_map[n - 1][m - 1];

    return answer;
}

void service() {

    vector<vector<int>> m = { {1,0,1,1,1} ,{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1} };
    cout << solution(m) << endl;
}

게임_맵_최단거리_END
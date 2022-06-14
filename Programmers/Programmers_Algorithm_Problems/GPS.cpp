#include "GPS.h"
#include <iostream>
#include <vector>
#include <limits>
#include <limits.h>

using namespace std;

GPS_BEGIN

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    
    // dp 사용.
    // dp[i][j] = 경로의 i번째 경로에 j번 위치가 왔을 때 최소 수정 횟수
    // 첫 번째 경로는 무조건 gps_log[0]이어야 하기 때문에
    // dp[0][gps_log] = 0

    int answer = INT_MAX;
    
    bool edge_map[201][201];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                edge_map[i][j] = true;
                edge_map[j][i] = true;
            }
            else {
                edge_map[i][j] = false;
                edge_map[j][i] = false;
            }
        }

    for (vector<int> edge : edge_list) {
        edge_map[edge[0]][edge[1]] = true;
        edge_map[edge[1]][edge[0]] = true;
    }

    int dp[100][201];

    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 201; j++)
            dp[i][j] = INT_MAX;

    dp[0][gps_log[0]] = 0;

    for (int i = 1; i < k; i++) {

        int origin = gps_log[i];

        for (int node = 1; node <= n; node++) {
            
            if (dp[i - 1][node] == INT_MAX)
                continue;

            for (int next = 1; next <= n; next++) {

                if (edge_map[node][next] == false)
                    continue;

                int modified = (origin == next) ? 0 : 1;

                dp[i][next] = min(dp[i][next], dp[i - 1][node] + modified);
            }
        }
    }


    if (dp[k - 1][gps_log[k - 1]] == INT_MAX)
        answer = -1;
    else
        answer = dp[k - 1][gps_log[k - 1]];


    return answer;
}

void service() {

    int n = 7;
    int m = 10;
    vector<vector<int>> el = { {1,2},{1,3},{2,3},{2,4},{3,4},{3,5},{4,6},{5,6},{5,7},{6,7} };
    int k = 6;
    vector<int> gl = { 1,2,3,3,6,7 };
    cout << solution(n, m, el, k, gl) << endl;
}

GPS_END
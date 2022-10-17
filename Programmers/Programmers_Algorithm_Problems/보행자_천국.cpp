#include "보행자_천국.h"
#include <iostream>
#include <vector>

using namespace std;

보행자_천국_BEGIN

#define MOD 20170805

#define FREE 0
#define PROHIBITION 1
#define ONLY_SAME_DIRECTION 2

pair<int, int> pos[500][500];

void init(int m, int n) {
    
    for (int r = 0; r < m; r++)
        for (int c = 0; c < n; c++)
            pos[r][c] = { 0, 0 };

    pos[0][1] = { 1,0 };
    pos[1][0] = { 0,1 };
}

void searchRoute(int m, int n, vector<vector<int>> city_map) {

    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {

            if (r == 0 && c == 0)
                continue;

            int roadStatus = city_map[r][c];

            if (roadStatus == FREE) {
                if (r + 1 < m)
                    pos[r + 1][c].second += (pos[r][c].first + pos[r][c].second) % MOD;
                if (c + 1 < n)
                    pos[r][c + 1].first += (pos[r][c].first + pos[r][c].second) % MOD;
            }
            else if (roadStatus == ONLY_SAME_DIRECTION) {
                if (r + 1 < m)
                    pos[r + 1][c].second += pos[r][c].second % MOD;
                if (c + 1 < n)
                    pos[r][c + 1].first += pos[r][c].first % MOD;
            }
        }
    }
}

int solution(int m, int n, vector<vector<int>> city_map) {
    
    int answer = 0;

    init(m, n);
    searchRoute(m, n, city_map);

    answer = (pos[m - 1][n - 1].first + pos[m - 1][n - 1].second) % MOD;

    return answer;
}

void service() {

    int m = 3;
    int n = 3;
    vector<vector<int>> cityMap = { {0,0,0},{0,0,0},{0,0,0} };

    cout << solution(m, n, cityMap) << endl;
}

보행자_천국_END
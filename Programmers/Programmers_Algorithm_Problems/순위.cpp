#include "순위.h"
#include <iostream>
#include <vector>

using namespace std;

순위_BEGIN

int solution(int n, vector<vector<int>> results) {
    
    // 플로이드 와샬 사용.

    int answer = 0;

    vector<vector<bool>> root_v(n + 1, vector<bool>(n + 1, false));

    for (int i = 1; i <= n; i++)
        root_v[i][i] = true;

    for (vector<int> result : results) {
        root_v[result[0]][result[1]] = true;
    }

    for (int mid = 1; mid <= n; mid++) {
        for (int start = 1; start <= n; start++) {
            for (int end = 1; end <= n; end++) {
                if (root_v[start][mid] && root_v[mid][end]) {
                    root_v[start][end] = true;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {

        bool canKnow = true;

        for (int j = 1; j <= n; j++) {
            if (root_v[i][j] == false && root_v[j][i] == false) {
                canKnow = false;
                break;
            }
        }

        if (canKnow == true)
            answer++;
    }

    return answer;
}

void service() {

    int n = 5;
    vector<vector<int>> r = { {4,3},{4,2},{3,2},{1,2},{2,5} };
    cout << solution(n, r) << endl;
}

순위_END
#include "µî±·±æ.h"
#include <iostream>
#include <vector>
#include <set>

using namespace std;

µî±·±æ_BEGIN

#define DIV_NUM 1000000007

int solution(int m, int n, vector<vector<int>> puddles) {
    
    int answer = 0;
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    dp[0][1] = 1;

    set<vector<int>> puddle_s;

    for (vector<int> puddle : puddles)
        puddle_s.insert({ puddle[1], puddle[0] });

    for (int dn = 1; dn <= n; dn++) {
        for (int dm = 1; dm <= m; dm++) {

            if (puddle_s.count({ dn, dm }) > 0)
                dp[dn][dm] = 0;
            else
                dp[dn][dm] = (dp[dn - 1][dm] + dp[dn][dm - 1]) % DIV_NUM;
        }
    }
    
    answer = dp[n][m];

    return answer;
}

void service() {

    int m = 4;
    int n = 3;
    vector<vector<int>> p = { {2, 2} };
    cout << solution(m, n, p) << endl;
}

µî±·±æ_END
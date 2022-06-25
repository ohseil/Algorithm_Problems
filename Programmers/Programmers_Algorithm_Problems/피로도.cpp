#include "피로도.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

피로도_BEGIN

int solution(int k, vector<vector<int>> dungeons) {
    
    // 던전의 수가 적기 때문에
    // 모든 순서를 확인해도 시간이 얼마 안걸린다.

    int answer = 0;

    sort(dungeons.begin(), dungeons.end());

    do {
        
        int temp = k;
        int count = 0;

        for (int i = 0; i < dungeons.size(); i++) {

            if (temp < dungeons[i][0])
                continue;

            temp -= dungeons[i][1];
            count++;
        }

        if (count > answer)
            answer = count;

    } while (next_permutation(dungeons.begin(), dungeons.end()));

    return answer;
}

void service() {

    int k = 80;
    vector<vector<int>> d = { {80,20},{50,40},{30,10} };
    cout << solution(k, d) << endl;
}

피로도_END
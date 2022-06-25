#include "�Ƿε�.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

�Ƿε�_BEGIN

int solution(int k, vector<vector<int>> dungeons) {
    
    // ������ ���� ���� ������
    // ��� ������ Ȯ���ص� �ð��� �� �Ȱɸ���.

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

�Ƿε�_END
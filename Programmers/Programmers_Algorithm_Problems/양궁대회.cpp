#include "양궁대회.h"
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

양궁대회_BEGIN

vector<int> solution(int n, vector<int> info) {

    // 각 과녁마다 점수를 얻기 위해 필요한 화살 수를 계산해서 저장한다.
    // 각 과녁마다 점수를 얻거나 얻지 않거나 2가지 경우 중 하나다.
    // 과녁은 0점 ~ 10점 총 11개다.
    // 모든 경우를 탐색한다.

    vector<int> answer(11, 0);
    int ansScore = -1;

    map<int, int> arrowInTargetM;

    int bScore = 0;

    for (int i = 0; i <= 10; i++) {

        int target = 10 - i;
        int arrowCount = info[i];

        arrowInTargetM[target] = arrowCount + 1;
    
        if (arrowCount > 0)
            bScore += target;
    }

    queue<vector<int>> q;
    q.push({ 0,0,0,0,0,0,0,0,0,0,0,n });

    for (int depth = 0; depth <= 10; depth++) {

        int qsize = q.size();

        for (int i = 0; i < qsize; i++) {

            vector<int> data = q.front();
            q.pop();

            q.push(data);

            if (data[11] >= arrowInTargetM[10 - depth]) {
                data[depth] = arrowInTargetM[10 - depth];
                data[11] -= arrowInTargetM[10 - depth];
                q.push(data);
            }
        }
    }

    while (q.empty() == false) {

        vector<int> data = q.front();
        q.pop();

        int score = 0;
        
        for (int i = 0; i <= 10; i++)
            if (data[i] > 1)
                score += (10 - i) * 2;
            else if (data[i] > 0)
                score += 10 - i;

        if (score <= bScore || score < ansScore)
            continue;

        if (data[11] > 0)
            data[10] += data[11];

        if (score > ansScore) {
            for (int j = 0; j <= 10; j++)
                answer[j] = data[j];
            ansScore = score;
        }
        else {

            for (int i = 10; i >= 0; i--) {
                if (data[i] > answer[i]) {
                    for (int j = 0; j <= 10; j++)
                        answer[j] = data[j];
                    ansScore = score;
                }
                else if (data[i] < answer[i])
                    break;
            }
        }
    }

    if (ansScore == -1)
        answer = { -1 };

    return answer;
}

void service() {

    int n = 10;
    vector<int> info = { 0,0,0,0,0,0,0,0,3,4,3 };

    vector<int> ans = solution(n, info);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

양궁대회_END
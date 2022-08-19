#include "��ô�ȸ.h"
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

��ô�ȸ_BEGIN

vector<int> solution(int n, vector<int> info) {

    // �� ���Ḷ�� ������ ��� ���� �ʿ��� ȭ�� ���� ����ؼ� �����Ѵ�.
    // �� ���Ḷ�� ������ ��ų� ���� �ʰų� 2���� ��� �� �ϳ���.
    // ������ 0�� ~ 10�� �� 11����.
    // ��� ��츦 Ž���Ѵ�.

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

��ô�ȸ_END
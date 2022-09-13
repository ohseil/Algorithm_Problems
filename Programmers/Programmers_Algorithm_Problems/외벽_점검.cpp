#include "외벽_점검.h"
#include <iostream>
#include <vector>

using namespace std;

외벽_점검_BEGIN

void checkPoints(vector<int>& dist, vector<int>& weak, int& n, int& answer) {

    for (int i = 0; i < weak.size(); i++) {

        int idx = i;
        int count = 0;

        for (int friendIdx = 0; friendIdx < dist.size(); friendIdx++) {

            int friendDist = dist[friendIdx];
            int nextIdx = idx;

            while (count < weak.size()) {

                int next = weak[nextIdx];

                if (next < weak[idx]) next += n;

                if (next - weak[idx] > friendDist)
                    break;

                count++;
                nextIdx = (nextIdx + 1) % weak.size();
            }

            if (count >= weak.size()) {
                if (friendIdx + 1 < answer) answer = friendIdx + 1;
                break;
            }

            idx = nextIdx;
        }

    }
}

void permutation(vector<int> dist, vector<int>& weak, int& n, int& answer, int depth) {

    if (depth == dist.size()) {
        checkPoints(dist, weak, n, answer);
        return;
    }

    for (int i = depth; i < dist.size(); i++) {
        swap(dist[i], dist[depth]);
        permutation(dist, weak, n, answer, depth + 1);
        swap(dist[i], dist[depth]);
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    
    // 검사를 시작할 때, 무조건 취약점부터 시작하는 것이 좋다.
    // 친구가 투입될 수 있는 모든 순서를 확인한다.
    // 친구는 최대 8명이므로 모든 순서를 고려해도 괜찮다고 판단했다.
    
    // 탐색 과정은 모든 취약점을 시작점으로 잡고
    // 순서대로 친구를 시계 방향으로 투입 시킨다.
    // 투입 시킬때는 무조건 취약점 위치에 투입시킨다.

    int answer = 9;

    permutation(dist, weak, n, answer, 0);

    if (answer == 9)
        answer = -1;

    return answer;
}

void service() {

    int n = 12;
    vector<int> weak = { 1,5,6,10 };
    vector<int> dist = { 1,2,3,4 };

    cout << solution(n, weak, dist) << endl;
}

외벽_점검_END
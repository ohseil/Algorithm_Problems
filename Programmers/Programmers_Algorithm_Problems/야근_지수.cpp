#include "야근_지수.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

야근_지수_BEGIN

long long solution(int n, vector<int> works) {
    
    // 우선 모든 일의 합이 n보다 작거나 같으면 남는 일은 0이다.

    // n보다 큰 경우는 다음과 같이 계산한다.
    // 일의 양이 a와 b가 있고 이 중 하나를 -1을 한다면,
    // 무조건 양이 많은 일을 줄이는 것이 좋다.

    // max heap을 사용해서 모든 work를 넣고,
    // 하나씩 꺼낸 후 -1을 하고 다시 넣는 작업을 n번 진행한다.
    // heap을 모두 조회해서 남은 일들을 계산한다.

    long long total = 0;

    for (int work : works)
        total += work;

    if (total <= n)
        return 0;

    long long answer = 0;    
    priority_queue<int> pq;

    for (int work : works)
        pq.push(work);

    while (n--) {

        int data = pq.top();
        pq.pop();

        pq.push(data - 1);
    }

    while (pq.empty() == false) {

        int data = pq.top();
        pq.pop();

        answer += (data * data);
    }

    return answer;
}

void service() {

    vector<int> w = { 4,3,3 };
    int n = 4;

    cout << solution(n, w) << endl;
}

야근_지수_END
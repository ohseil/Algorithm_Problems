#include "두_큐_합_같게_만들기.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

두_큐_합_같게_만들기_BEGN

int solution(vector<int> queue1, vector<int> queue2) {

    // 우선 두 큐의 원소의 총 합이 홀수면 무조건 나눌 수 없다.
    // 각 큐의 원소의 합을 보고 큰 쪽에서 작은쪽으로 이동한다.
    // 이렇게 해야하는 이유를 생각해 보면,
    // 만약 작은쪽에서 먼저 이동을 한 후에 큰쪽에서 이동을 하는 경우가
    // 답이 될 가능성이 있지 않을까 라는 가정에 대해 생각해 보면,
    // 아무리 먼저 이동을 하더라도 나중에는 무조건 큰쪽에서 작은쪽으로 이동을 해야하는데
    // 이때 이동을 하는 숫자의 순서는 큐이기 때문에 절대 바뀌지 않는다.
    // 그렇기 때문에 큰쪽에서 작은쪽으로 이동한다.

    // 그렇다면, 언제까지 이동해야 하는지 생각해 보면
    // 위의 규칙대로 이동하면 결국 반복이 된다.
    // 반복되는 시점이 언제인지 찾아야되는데 사실 정확하게 찾지는 못했다.
    // 단순히 2개의 큐에서 번갈아 가면서 이동하는 경우는 2n이 반복 주기이겠지만
    // 다른 경우들은 정확히 언제가 반복 주기인지 모르겠다.
    // 2n-2로 이동 횟수를 잡으면 모든 케이스를 통과할 수는 있지만 정확한 값은 아니다.
    // 다른 예외 케이스에서 틀릴 수 있다.
    // 그래서 그냥 3n으로 설정했다.

    int answer = 0;

    queue<int> q1, q2;
    long long q1Sum = 0, q2Sum = 0;

    for (int num : queue1) {
        q1.push(num);
        q1Sum += num;
    }
    for (int num : queue2) {
        q2.push(num);
        q2Sum += num;
    }

    if ((q1Sum + q2Sum) % 2 != 0)
        return -1;

    if (q1Sum == q2Sum)
        return 0;

    bool isSame = false;

    for (int i = 0; i < queue1.size() *3; i++) {

        if (q1Sum < q2Sum) {
            q1Sum += q2.front();
            q2Sum -= q2.front();
            q1.push(q2.front());
            q2.pop();
        }
        else {
            q2Sum += q1.front();
            q1Sum -= q1.front();
            q2.push(q1.front());
            q1.pop();
        }

        answer++;

        if (q1Sum == q2Sum) {
            isSame = true;
            break;
        }
    }

    if (isSame == false)
        answer = -1;

    return answer;
}

void service() {

    vector<int> q1 = { 1,1 };
    vector<int> q2 = { 1,5 };
    
    cout << solution(q1, q2) << endl;
}

두_큐_합_같게_만들기_END
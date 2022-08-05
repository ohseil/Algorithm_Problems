#include "�߱�_����.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

�߱�_����_BEGIN

long long solution(int n, vector<int> works) {
    
    // �켱 ��� ���� ���� n���� �۰ų� ������ ���� ���� 0�̴�.

    // n���� ū ���� ������ ���� ����Ѵ�.
    // ���� ���� a�� b�� �ְ� �� �� �ϳ��� -1�� �Ѵٸ�,
    // ������ ���� ���� ���� ���̴� ���� ����.

    // max heap�� ����ؼ� ��� work�� �ְ�,
    // �ϳ��� ���� �� -1�� �ϰ� �ٽ� �ִ� �۾��� n�� �����Ѵ�.
    // heap�� ��� ��ȸ�ؼ� ���� �ϵ��� ����Ѵ�.

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

�߱�_����_END
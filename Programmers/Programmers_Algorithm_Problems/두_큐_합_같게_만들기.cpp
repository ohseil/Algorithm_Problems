#include "��_ť_��_����_�����.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

��_ť_��_����_�����_BEGN

int solution(vector<int> queue1, vector<int> queue2) {

    // �켱 �� ť�� ������ �� ���� Ȧ���� ������ ���� �� ����.
    // �� ť�� ������ ���� ���� ū �ʿ��� ���������� �̵��Ѵ�.
    // �̷��� �ؾ��ϴ� ������ ������ ����,
    // ���� �����ʿ��� ���� �̵��� �� �Ŀ� ū�ʿ��� �̵��� �ϴ� ��찡
    // ���� �� ���ɼ��� ���� ������ ��� ������ ���� ������ ����,
    // �ƹ��� ���� �̵��� �ϴ��� ���߿��� ������ ū�ʿ��� ���������� �̵��� �ؾ��ϴµ�
    // �̶� �̵��� �ϴ� ������ ������ ť�̱� ������ ���� �ٲ��� �ʴ´�.
    // �׷��� ������ ū�ʿ��� ���������� �̵��Ѵ�.

    // �׷��ٸ�, �������� �̵��ؾ� �ϴ��� ������ ����
    // ���� ��Ģ��� �̵��ϸ� �ᱹ �ݺ��� �ȴ�.
    // �ݺ��Ǵ� ������ �������� ã�ƾߵǴµ� ��� ��Ȯ�ϰ� ã���� ���ߴ�.
    // �ܼ��� 2���� ť���� ������ ���鼭 �̵��ϴ� ���� 2n�� �ݺ� �ֱ��̰�����
    // �ٸ� ������ ��Ȯ�� ������ �ݺ� �ֱ����� �𸣰ڴ�.
    // 2n-2�� �̵� Ƚ���� ������ ��� ���̽��� ����� ���� ������ ��Ȯ�� ���� �ƴϴ�.
    // �ٸ� ���� ���̽����� Ʋ�� �� �ִ�.
    // �׷��� �׳� 3n���� �����ߴ�.

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

��_ť_��_����_�����_END
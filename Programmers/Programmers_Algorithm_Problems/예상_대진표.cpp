#include "����_����ǥ.h"
#include <iostream>

using namespace std;

����_����ǥ_BEGIN

int solution(int n, int a, int b)
{
    // ��ȣ�� 0������ �����ϰ� �ϸ�
    // ���� �ܰ迡���� /2�� ���� ���� �����ڳ��� ����.
    // �̱� ����� ���� �ܰ迡 ��ȣ�� /2�� ���� �ȴ�.

    int answer = 1;

    a--;
    b--;

    while (a / 2 != b / 2) {
        a /= 2;
        b /= 2;
        answer++;
    }
    
    return answer;
}

void service() {

    cout << solution(8, 4, 7) << endl;
}

����_����ǥ_END
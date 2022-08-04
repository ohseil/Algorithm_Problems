#include "����_���.h"
#include <iostream>
#include <vector>

using namespace std;

����_���_BEGIN

int getDivisor(long long num) {

    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0 && num / i <= 10000000)
            return num / i;
    }

    return -1;
}

vector<int> solution(long long begin, long long end) {

    // ��ġ x�� �������� �������� ��� ��ȣ��
    // �ᱹ ������ �� �ִ� ��� �� ���� ū ��ȣ�� ����̴�.
    // x�� ������� ���ؼ�
    // ���� ū ��� ��ȣ���� �۰ų� ���� ����� �ִٸ� �� ��ȣ�� ������ ��� ��ȣ��.
    // ������ x�� �Ҽ���� ��ȣ�� 1�� ��� �ܿ� �������� ����� ���ٴ� ���� �ǹ��Ѵ�.

    vector<int> answer;

    if (begin == 1) {
        answer.push_back(0);
        begin++;
    }

    for (long long i = begin; i <= end; i++) {
        
        int n = getDivisor(i);

        if (n == -1)
            answer.push_back(1);
        else
            answer.push_back(n);
    }

    return answer;
}

void service() {

    long long begin = 1;
    long long end = 10;
    
    vector<int> ans = solution(begin, end);
    for (int a : ans)
        cout << a << " ";
    cout << endl;
}

����_���_END
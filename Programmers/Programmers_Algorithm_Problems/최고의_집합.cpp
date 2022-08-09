#include "�ְ���_����.h"
#include <iostream>
#include <vector>

using namespace std;

�ְ���_����_BEGIN

vector<int> solution(int n, int s) {
    
    // �켱 n���� �ڿ����� s�� ���� �� ���� ����,
    // ���� �ߺ��� �����ϱ� ������ n���� 1�� ���� �� ���� s < n �� ��� �ۿ� ����.

    // ���� �� ���ҵ��� ���� ���� ū ���� ���� �� ���̰� �ּ��� ����̴�.
    // ���� s / n �� �⺻ ���� x�� ���ϰ� s % n�� (n-(s%n))���� x���� ������ �����ش�.
    // �ᱹ���� ������ {x,x, ..., x+1,x+1} �̷� ���·� ������ �� ���̴�.

    if (s < n)
        return vector<int>({ -1 });

    vector<int> answer;
    
    int quotient = s / n;
    int remainder = s % n;

    for (int i = 0; i < n; i++) {
        if (i < n - remainder)
            answer.push_back(quotient);
        else
            answer.push_back(quotient + 1);
    }

    return answer;
}

void service() {

    int n = 2;
    int s = 9;

    vector<int> ans = solution(n, s);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

�ְ���_����_END
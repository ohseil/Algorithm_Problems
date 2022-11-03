#include "������_����_�̵�.h"
#include <iostream>

using namespace std;

������_����_�̵�_BEGIN

int getJumpCountInMove(int n) {

    if (n == 0)
        return 0;

    if (n % 2 == 0) return getJumpCountInMove(n / 2);
    else return getJumpCountInMove(n - 1) + 1;
}

int solution(int n)
{
    // ���� ���Ḧ ���� ����ϱ� ���ؼ���
    // �����̵����� �ִ��� ���� �̵��ؾ� �Ѵٴ� �ǹ̴�.

    // n�� �����ϱ� �ٷ� ������ ��ġ�� ������ ����,
    // n�� �����ϱ� ���� ���������� �����̵��� ���� ��,
    // ���� ���� �̵��ϴ� ����
    // n�� ¦���� ���� n / 2 ��ġ���� �����̵�,
    // n�� Ȧ���� ���� (n-1)/2 ��ġ���� �����̵� �Ŀ� n-1 ��ġ���� ��ĭ �����ϴ� ����.

    // ���������� n/2 �Ǵ� (n-1)/2 ��ġ�� �̵��ϴµ� ���� ���� ������ �����̵��ϴ� ��쵵 ����.
    
    // n ��ġ���� �����ؼ� �ݴ�� �̵��� ������.
    // n ��ġ���� �����ؼ� ¦���� ��쿡�� �����̵�,
    // Ȧ���� ��쿡�� -1 ĭ �����ؼ� ¦���� ����� �����̵� �Ѵ�.

    int ans = getJumpCountInMove(n);

    return ans;
}

void service() {

    int n = 5;

    cout << solution(n) << endl;
}

������_����_�̵�_END
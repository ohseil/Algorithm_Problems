#include "����_ū_����.h"
#include <iostream>
#include <bitset>

using namespace std;

����_ū_����_BEGIN

int solution(int n) {
    
    // �ܼ��ϰ� 1�� ������Ű�鼭 Ȯ���Ѵ�.
    // ������ ����, ������ n�� ���� 1�� ������ ���� ���ڱ��� ������Ű�� Ƚ���� �� �ȵȴ�.
    // �� ����� bitset�� ����Ѵ�.
    // int ���̹Ƿ� bitset�� ��� bit ������ 32���� �����ϰ� n�� bit 1�� ������ �����س��´�.
    // bitset�� count() �Լ��� ����ϸ� �ٷ� ���� �� �ִ�.
    // bit 1�� ������ ���� ���ڰ� ���ö����� 1�� ������Ų��.

    int answer = n + 1;

    int origin_count = bitset<32>(n).count();

    while (bitset<32>(answer).count() != origin_count) answer++;

    return answer;
}

void service() {

    int n = 5;
    cout << solution(n) << endl;

}

����_ū_����_END
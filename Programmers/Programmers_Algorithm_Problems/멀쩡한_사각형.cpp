#include "������_�簢��.h"
#include <iostream>

using namespace std;

������_�簢��_BEGIN

long long findGCD(int a, int b) {
	if (a % b == 0) return b;
	else return findGCD(b, a % b);
}

long long solution(int w, int h) {
	
	// ��Ģ�� ã�ƺ���,
	// ���� ũ���� �簢������ ������ ��,
	// ������� ���ϴ� �簢���� ������ ���� �� �̾��� �ִ� ���´�.
	// �������� ũ��� �ּ� ũ��� ������ �ϴµ�
	// �̰��� w�� h�� �ִ������� x���� ������ ����.
	
	// �ּ� ũ���� ���簢���� w�� h�� minW, minH��� �Ҷ�,
	// �ּ� ũ���� ���簢������ ���ԵǾ� �ִ� ������� ���ϴ� �簢�� ������
	// minW + minH - 1�̴�.

	// ��� ������ �簢�� ������ w * h - (minW + minH - 1) * x�� �ȴ�.

	long long answer = 1;
	
	long long gcdNum = findGCD(w, h);

	int minW = w / gcdNum;
	int minH = h / gcdNum;
	
	int unavailableCount = (minW + minH - 1) * gcdNum;

	answer = (long long)w * h - unavailableCount;

	return answer;
}

void service() {

	int w = 8;
	int h = 12;

	cout << solution(w, h) << endl;
}

������_�簢��_END
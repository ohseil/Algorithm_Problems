#include "���̽�ƽ.h"

int ���̽�ƽ::solution(string name) {

	// ������ ��� 'A'�� �ƴ� ���ĺ��� �����ؾ� �ϱ� ������
	// ���߿� ��� ���ĺ��� Ȯ���ؼ� ����Ͽ� �ʿ��� ���̽�ƽ ������ Ƚ�� +.
	
	// ����� �� �ִ� ��ȸ ��θ� ���캸��
	// 'A'�� �ƴ� ���ĺ��� B��� �Ѵٸ� B���� ��ġ�� ������ �� ����� �Ѵ�.
	// 1. ó������ ������ ��ȸ�ϴ� ���
	// 2. ó�� ��ġ -> �߰��� B -> ó�� ��ġ -> ������ ��ġ -> �߰��� B ���Ŀ� ó�� ������ B
	// 3. ó�� ��ġ -> ������ ��ġ -> �߰��� B ���Ŀ� ó�� ������ B -> ������ ��ġ -> ó�� ��ġ -> �߰��� B
	// 3���� ��� �� ���� ���� �̵� Ƚ���� ��ΰ� ���̴�.

	int answer = 0;

	int len = name.length();
	int cost = name.length();

	for (int i = 0; i < len; i++) {

		if (name[i] == 'A')
			continue;

		int idx = 0;

		for (int j = i + 1; j < len; j++) {
			if (name[j] != 'A') {
				idx = j;
				break;
			}
		}

		if (idx != 0)
			idx = len - idx;

		cost = min(cost, min(2 * i + idx, i + 2 * idx));
	}

	if (cost == name.length())
		cost = 0;

	answer = (len - 1 < cost) ? (len - 1) : cost;

	for (char ch : name)
		answer += (ch - 'A' < 'Z' - ch + 1) ? (ch - 'A') : ('Z' - ch + 1);

	return answer;
}



void ���̽�ƽ::service() {

    string str = "AAAAA";
    cout << solution(str) << endl;
}
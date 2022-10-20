#include "�ﰢ_������.h"
#include <iostream>
#include <vector>

using namespace std;

�ﰢ_������_BEGIN

int maxNum;

int num;
int dif;
int pos;

void init(vector<int>& pyramid, int n) {
    
    maxNum = (n * (n + 1) / 2);

    // padding
    pyramid.assign((n + 1) * (n + 2) / 2 + 1, 0);
    for (int i = (n * (n + 1) / 2) + 1; i < pyramid.size(); i++)
        pyramid[i] = -1;

    pyramid[1] = 1;
    num = 2;
    dif = 1;
    pos = 1;
}

void fillLeftMoving(vector<int>& pyramid) {
	while (pyramid[pos + dif] == 0) {
        pos += dif;
        pyramid[pos] = num;
        num++;
        dif++;
    }
}

void fillBottomMoving(vector<int>& pyramid) {
	while (pyramid[pos + 1] == 0) {
        pos++;
        pyramid[pos] = num;
        num++;
    }
}

void fillRightMoving(vector<int>& pyramid) {
	while (pyramid[pos - dif] == 0) {
        pos -= dif;
        pyramid[pos] = num;
        num++;
        dif--;
    }
}

vector<int> solution(int n) {
    
    // ���ڸ� ä���ִ� ��Ģ�� ã�´�.
    // 1. ���� �밢�� ���� �̵�
    // 2. �Ʒ��� ���� �̵�
    // 3. ������ �밢�� ���� �̵�
    // �� ������� �̵��ϸ鼭 ���ڸ� ä���ִ´�.
    // �̵� ������ �ٲ�� ������ ������ ����ų� �̹� ä���� �ִ� ����.

    // 1���� �迭�� ����Ѵ�.
    
    // ���� �밢���� ���� �̵��� ���� index�� dif��ŭ �����ϴµ�,
    // dif�� �� �� ������ ������ 1�� �����Ѵ�.

    // �Ʒ����� ���� �̵��� ���� �ܼ��� index�� +1�� �����Ѵ�.
    
    // ������ �밢���� ���� �̵��� ���� ���� �밢���� ���� ������ �̵����� ���� dif ���� ��������
    // index�� dif��ŭ �����Ѵ�.
    // dif�� �� �� �ö� ������ 1�� �����Ѵ�.

    // (n * (n + 1) / 2) ���ڱ��� ä������ �����Ѵ�.

    vector<int> answer;
    
    vector<int> pyramid;

    init(pyramid, n);

	while (num <= maxNum) {
		fillLeftMoving(pyramid);
		fillBottomMoving(pyramid);
		fillRightMoving(pyramid);
	}

    for (int i = 1; i <= maxNum; i++)
        answer.push_back(pyramid[i]);

    return answer;
}

void service() {

    int n = 4;
    
    vector<int> ans = solution(n);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

�ﰢ_������_END
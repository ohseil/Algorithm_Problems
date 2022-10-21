#include "ǳ��_��Ʈ����.h"
#include <iostream>
#include <vector>

using namespace std;

ǳ��_��Ʈ����_BEGIN

void setLeftMinNums(vector<int>& leftMinNums, vector<int>& a) {
    
    leftMinNums[0] = a[0];
    
    for (int i = 1; i < a.size(); i++) {
        if (a[i] < leftMinNums[i - 1]) leftMinNums[i] = a[i];
        else leftMinNums[i] = leftMinNums[i - 1];
    }
}

void setRightMinNums(vector<int>& rightMinNums, vector<int>& a) {

    rightMinNums[a.size() - 1] = a[a.size() - 1];

    for (int i = a.size() - 2; i >= 0; i--) {
        if (a[i] < rightMinNums[i + 1]) rightMinNums[i] = a[i];
        else rightMinNums[i] = rightMinNums[i + 1];
    }
}

int solution(vector<int> a) {
    
    // ���Ƿ� ������ ǳ���� ������� �غ���.
    // ���� ������ ǳ���� ���� ���� ����ǳ���̶�� �Ѵٸ�,
    // ��� ��Ʈ���� �ᱹ ������ ǳ���� ���� �ȴ�.
    
    // ������ ǳ���� 2��°�� ���� ����ǳ���̶�� �Ѵٸ�,
    // ���� ���� ����ǳ���� ��� �ص� ���������� ���� �ǰ�,
    // ������ ǳ���� �����ϰ� �ȴ�. �� �� ���� ǳ���� ��Ʈ���� �ൿ�� �ϸ� �����ϴ�.

    // ������� ������ ����,
    // �ᱹ���� ������ ǳ������ ū ����ǳ���� ����ų�
    // ������ ǳ������ ���� ���ڸ� �ϳ��� ���ܾ� ������ ǳ���� �������� ���� �� �ִ�.
    // ������ ǳ������ ���� ����ǳ���� ���������� �ᱹ �����ϰ� �Ǹ�,
    // ���������� ������ ǳ������ ���� ����ǳ���� �ϳ��� ���� �ȴ�.

    // �׷���,
    // ������ ǳ���� �������� ���� ǳ����� ������ ǳ������ ���������� ������ �� ����.
    // �׷��� ������ �ᱹ, ������ ǳ���� ���������� ��������
    // ������ ǳ������ ���� ����ǳ���� �������� �ʰų�, ���ʿ��� �����ϰų�, �����ʿ��� �����ؾ� �Ѵ�.

    // �� ǳ���� ��ġ���� ���� ǳ���� �� ���� ���� ���ڿ� ������ ǳ���� �� ���� ���� ���ڸ� �˱� ����
    // �迭 2���� �����.
    // ǳ�� �迭�� �������� �ѹ� ��ȸ, ���������� �ѹ� ��ȸ�ؼ� �� 2�� ��ȸ�Ѵ�.
    // ��ȸ�ϸ鼭 �� ��ġ�� �������� ���� ��ȸ�ϸ鼭 Ȯ���ߴ� ���� �� ���� ���� ���ڸ� �����Ѵ�.

    // �� 2���� �迭�� ����ϸ� ���Ƿ� ǳ���� �������� ��,
    // ������ ǳ���� �������� ���ʰ� �����ʿ� �� ���� ���ڰ� �����ϴ��� O(1) �ð����⵵�� Ȯ���� �� �ִ�.

    int answer = 0;
    
    vector<int> leftMinNums(a.size()), rightMinNums(a.size());

    setLeftMinNums(leftMinNums, a);
    setRightMinNums(rightMinNums, a);

    for (int i = 0; i < a.size(); i++) {

        if (leftMinNums[i] >= a[i] || rightMinNums[i] >= a[i])
            answer++;
    }

    return answer;
}

void service() {

    vector<int> a = { 9,-1,-5 };

    cout << solution(a) << endl;
}

ǳ��_��Ʈ����_END
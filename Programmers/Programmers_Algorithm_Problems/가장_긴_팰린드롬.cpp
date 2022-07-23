#include "����_��_�Ӹ����.h"
#include <iostream>

using namespace std;

����_��_�Ӹ����_BEGIN

int solution(string s)
{
    // �� ��ġ�� ���ڸ� �������� �� ������ ������ Ű��鼭 Ž���Ѵ�.
    // 2���� ��찡 �ִµ� Ȧ�� ���� ���� ¦�� ���� ����.
    // Ȧ�� ���� �ϳ��� ���ڸ� �������� �� ������ Ž���Ѵ�.
    // ¦�� ���� 2���� ���� ���ڸ� �������� �� ������ Ž���Ѵ�.
    // �ð����⵵�� O(n^2)������ ���ڿ��� ���̰� �ִ� 2500�̱� ������ �������.
    
    int answer = 0;
    int len = s.length();

    // Ȧ�� ���� ���ڸ� ������ �Ӹ����
    for (int i = 0; i < len; i++) {

        int stand = i;
        int dist = 1;
        int count = 1;

        while (stand - dist >= 0 &&
            stand + dist < len &&
            s[stand - dist] == s[stand + dist]) {

            dist++;
            count += 2;
        }

        if (answer < count)
            answer = count;
    }

    // ¦�� ���� ���ڸ� ������ �Ӹ����
    for (int i = 0; i < len - 1; i++) {

        if (s[i] != s[i + 1])
            continue;

        int stand1 = i, stand2 = i + 1;
        int dist = 1;
        int count = 2;

        while (stand1 - dist >= 0 &&
            stand2 + dist < len &&
            s[stand1 - dist] == s[stand2 + dist]) {

            dist++;
            count += 2;
        }

        if (answer < count)
            answer = count;
    }

    return answer;
}

void service() {

    string s = "abcdcba";
    cout << solution(s) << endl;
}

����_��_�Ӹ����_END
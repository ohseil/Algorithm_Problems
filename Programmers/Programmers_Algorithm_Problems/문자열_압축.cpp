#include "���ڿ�_����.h"
#include <iostream>
#include <string>

using namespace std;

���ڿ�_����_BEGIN

int solution(string s) {
    
    // ��� ��츦 Ž���Ѵ�.
    // 1�������� �����ؼ� (s.length() / 2)�������� �����غ���.
    // s.length() / 2 ���� ũ�� �ڸ��� ����
    // ���� ���̰� 2�� �̻� ������ �ʱ� ������ �ǹ� ����.

    int answer = s.length();
    
    for (int divLen = 1; divLen <= s.length() / 2; divLen++) {

        int totalLen = 0;

        string curFindString = s.substr(0, divLen);
        int sameCount = 1;

        int idx = divLen;

        while (idx <= (s.length() - divLen)) {

            string str = s.substr(idx, divLen);

            if (str == curFindString) {
                sameCount++;
            }
            else {
                if (sameCount > 1) totalLen += to_string(sameCount).length();
                totalLen += curFindString.length();
                curFindString = str;
                sameCount = 1;
            }

            idx += divLen;
        }

        if (sameCount > 1) totalLen += to_string(sameCount).length();
        totalLen += curFindString.length();

        if (idx < s.length())
            totalLen += (s.length() - idx);

        if (totalLen < answer)
            answer = totalLen;
    }

    return answer;
}

void service() {

    string s = "abcabcabcabcdededededede";
    cout << solution(s) << endl;
}

���ڿ�_����_END
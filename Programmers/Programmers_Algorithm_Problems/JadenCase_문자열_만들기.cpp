#include "JadenCase_���ڿ�_�����.h"
#include <iostream>
#include <string>

using namespace std;

JadenCase_���ڿ�_�����_BEGIN

string solution(string s) {

    // ���� ���� �����ؼ� ����Ѵ�.
    // ���´� ���� ���¿� ������ �ƴ� ���·� �����Ѵ�.
    
    // ó������ ���� ���·� �����Ѵ�.
    // ���ڿ��� ���ڸ� ���������� ��ȸ�ϸ鼭 �����Ѵ�.
    // ���� ���¿��� ��ȸ���� ���ڰ� ������ �ƴ� ��� ������ �ƴ� ���·� �����Ѵ�.
    // �� ��, �����ϸ鼭 ù �ܾ��� �����̱� ������ ù ���� ó���� ���� �� answer�� ���δ�.
    // �ܾ��� �ι�° ���ں��ʹ� �ҹ��ڷ� answer�� ���δ�.
    
    // ������ �ƴ� ���¿��� ��ȸ���� ���ڰ� ������ ��� ���� ���·� �����Ѵ�.
    // ���ڿ��� ���������� �����Ѵ�.

    string answer = "";

    bool isSpace = true;

    for (int i = 0; i < s.length(); i++) {

        if (isSpace == true) {

            if (s[i] != ' ') {
                if (('0' <= s[i] && s[i] <= '9') == false)
                    answer += toupper(s[i]);
                else
                    answer += s[i];

                isSpace = false;
            }
            else
                answer += s[i];

        }
        else {

            if (('0' <= s[i] && s[i] <= '9') == false)
                answer += tolower(s[i]);
            else
                answer += s[i];

            if (s[i] == ' ')
                isSpace = true;
        }
    }

    return answer;
}

void service() {

	string str = "for the last week";
    cout << solution(str) << endl;
}

JadenCase_���ڿ�_�����_END
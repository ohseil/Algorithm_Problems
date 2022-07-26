#include "�ùٸ�_��ȣ.h"
#include <iostream>

using namespace std;

�ùٸ�_��ȣ_BEGIN

bool solution(string s)
{

    // ���� ���� �̿�.
    // open_count�� stack�� �� '('�� ����

    bool answer = true;

    int open_count = 0;

    for (char ch : s) {

        if (ch == '(') {
            open_count++;
        }
        else {

            if (open_count == 0)
                return false;

            open_count--;
        }
    }

    answer = (open_count == 0);

    return answer;
}

void service() {

    string s = "()()";
    cout << solution(s) << endl;
}

�ùٸ�_��ȣ_END
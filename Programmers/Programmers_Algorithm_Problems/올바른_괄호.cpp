#include "올바른_괄호.h"
#include <iostream>

using namespace std;

올바른_괄호_BEGIN

bool solution(string s)
{

    // 스택 구조 이용.
    // open_count는 stack에 들어간 '('의 개수

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

올바른_괄호_END
#include "JadenCase_문자열_만들기.h"
#include <iostream>
#include <string>

using namespace std;

JadenCase_문자열_만들기_BEGIN

string solution(string s) {

    // 상태 값을 저장해서 사용한다.
    // 상태는 공백 상태와 공백이 아닌 상태로 구분한다.
    
    // 처음에는 공백 상태로 시작한다.
    // 문자열의 문자를 순차적으로 조회하면서 진행한다.
    // 공백 상태에서 조회중인 문자가 공백이 아닌 경우 공백이 아닌 상태로 변경한다.
    // 이 때, 변경하면서 첫 단어의 문자이기 때문에 첫 문자 처리를 해준 후 answer에 붙인다.
    // 단어의 두번째 문자부터는 소문자로 answer에 붙인다.
    
    // 공백이 아닌 상태에서 조회중인 문자가 공백인 경우 공백 상태로 변경한다.
    // 문자열이 끝날때까지 진행한다.

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

JadenCase_문자열_만들기_END
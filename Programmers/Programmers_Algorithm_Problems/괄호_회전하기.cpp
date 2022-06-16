#include "괄호_회전하기.h"
#include <iostream>
#include <stack>

using namespace std;

괄호_회전하기_BEGIN

bool checkCorrect(string str) {

    stack<char> st;

    for (int i = 0; i < str.length(); i++) {

        char bracket = str[i];

        if (bracket == '(' || bracket == '{' || bracket == '[') {
            st.push(bracket);
        }
        else {

            if (st.empty() == true)
                return false;

            char data = st.top();
            st.pop();

            if (data == '(' && bracket != ')') return false;
            else if (data == '{' && bracket != '}') return false;
            else if (data == '[' && bracket != ']') return false;
        }
    }

    return st.empty();
}

string rotateStr(string str) {
    return str.substr(1) + str[0];
}

int solution(string s) {
    
    int answer = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (checkCorrect(s) == true)
            answer++;
        s = rotateStr(s);
    }

    return answer;
}

void service() {

    string str = "}]()[{";
    cout << solution(str) << endl;
}

괄호_회전하기_END
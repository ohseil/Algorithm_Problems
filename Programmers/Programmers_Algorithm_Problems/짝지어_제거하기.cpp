#include "짝지어_제거하기.h"
#include <iostream>
#include <stack>

using namespace std;

짝지어_제거하기_BEGIN

int solution(string s)
{
    // stack을 사용했다.
    // 문자열의 문자를 차례대로 확인한다.
    // stack의 top문자와 비교해서 일치하면 stack에서 top을 제거한다.
    // 일치하지 않는다면 stack에 문자를 삽입한다.
    // 이 과정이 끝난 후 stack에 문자가 남아있다면 성공하지 못한 것이다.

    int answer = -1;

    stack<char> st;

    for (char ch : s) {

        if (st.empty() == true || st.top() != ch)
            st.push(ch);
        else
            st.pop();
    }

    if (st.empty() == true)
        answer = 1;
    else
        answer = 0;

    return answer;
}

void service() {

    string s = "baabaa";
    
    cout << solution(s) << endl;
}

짝지어_제거하기_END
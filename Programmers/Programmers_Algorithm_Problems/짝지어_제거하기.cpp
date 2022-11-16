#include "¦����_�����ϱ�.h"
#include <iostream>
#include <stack>

using namespace std;

¦����_�����ϱ�_BEGIN

int solution(string s)
{
    // stack�� ����ߴ�.
    // ���ڿ��� ���ڸ� ���ʴ�� Ȯ���Ѵ�.
    // stack�� top���ڿ� ���ؼ� ��ġ�ϸ� stack���� top�� �����Ѵ�.
    // ��ġ���� �ʴ´ٸ� stack�� ���ڸ� �����Ѵ�.
    // �� ������ ���� �� stack�� ���ڰ� �����ִٸ� �������� ���� ���̴�.

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

¦����_�����ϱ�_END
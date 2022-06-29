#include "�ֽİ���.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

�ֽİ���_BEGIN

vector<int> solution(vector<int> prices) {
    
    // stack ���
    // �ֽ� ������ ���������� Ȯ���ϸ鼭 stack�� �����Ѵ�.
    // �����ϱ� ���� stack �ȿ� �����͵��� �ִٸ�
    // ���ʴ�� ������ Ȯ���ؼ� ���� ���ݺ��� ������ stack���� �����ϰ� �� �迭�� �����Ѵ�.

    vector<int> answer(prices.size());
    
    stack<pair<int, int>> st;

    for (int i = 0; i < prices.size(); i++) {

        int price = prices[i];

        if (st.empty() == true) {
            st.push({ price, i });
            continue;
        }

        while (st.empty() == false) {

            if (st.top().first <= price)
                break;

            answer[st.top().second] = i - st.top().second;
            st.pop();
        }

        st.push({ price, i });
    }

    while (st.empty() == false) {
        answer[st.top().second] = prices.size() - 1 - st.top().second;
        st.pop();
    }

    return answer;
}

void service() {

    vector<int> p = { 1,2,3,2,3 };
    vector<int> ans = solution(p);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;

}

�ֽİ���_END
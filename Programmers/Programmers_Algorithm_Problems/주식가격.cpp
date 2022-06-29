#include "주식가격.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

주식가격_BEGIN

vector<int> solution(vector<int> prices) {
    
    // stack 사용
    // 주식 가격을 순차적으로 확인하면서 stack에 삽입한다.
    // 삽입하기 전에 stack 안에 데이터들이 있다면
    // 차례대로 가격을 확인해서 지금 가격보다 높으면 stack에서 제거하고 답 배열에 저장한다.

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

주식가격_END
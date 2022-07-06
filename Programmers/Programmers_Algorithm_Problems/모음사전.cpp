#include "모음사전.h"
#include <iostream>
#include <vector>

using namespace std;

모음사전_BEGIN

void initOrder(vector<int>& v) {
    v[(int)'A'] = 0;
    v[(int)'E'] = 1;
    v[(int)'I'] = 2;
    v[(int)'O'] = 3;
    v[(int)'U'] = 4;
}

void initValue(vector<int>& v) {
    v[4] = 1;
    v[3] = v[4] * 5 + 1;
    v[2] = v[3] * 5 + 1;
    v[1] = v[2] * 5 + 1;
    v[0] = v[1] * 5 + 1;
}

int solution(string word) {
    
    // 규칙을 찾아 해결했다.

    int answer = 0;

    vector<int> order_v(91);
    vector<int> value_v(5);

    initOrder(order_v);
    initValue(value_v);

    for (int i = 0; i < word.length(); i++) {

        char ch = word[i];
        
        int count = 1;

        count += (value_v[i] * (order_v[word[i]] - order_v[(int)'A']));

        answer += count;
    }

    return answer;
}

void service() {

    string str = "AAAE";
    cout << solution(str) << endl;
}

모음사전_END
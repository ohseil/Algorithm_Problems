#include "큰_수_만들기.h"
#include <iostream>
#include <string>

using namespace std;

큰_수_만들기_BEGIN

string solution(string number, int k) {
    
    // 맨 윗자리부터 탐색을 시작한다.
    // 맨 윗자리를 기준으로 k개의 수 중 가장 큰 수를 확인하고,
    // 큰 수를 기준으로 윗 자리 수들을 모두 제거한다.
    // 제거한 수 만큼 k에서 뺀다.
    // 이 큰 수의 다음 index부터 다시 위 과정을 진행한다.

    string answer = "";
    
    int len = number.length();
    int idx = 0;

    while (idx < len && (len - idx) > k && k > 0) {

        int big = -1;
        int b_idx = -1;

        for (int i = idx; i <= idx + k; i++) {
            
            int num = number[i] - 48;

            if (num > big) {
                big = num;
                b_idx = i;
            }
        }

        answer += to_string(big);
        k -= (b_idx - idx);
        idx = b_idx + 1;

    }

    if (k == 0 && idx < len)
        answer += number.substr(idx);

    return answer;
}

void service() {

    string str = "4177252841";
    int k = 4;
    cout << solution(str, k) << endl;

}

큰_수_만들기_END
#include "숫자의_표현.h"
#include <iostream>

using namespace std;

숫자의_표현_BEGIN

int solution(int n) {
    
    // 연속된 숫자라는 것은 각 숫자의 차이가 1이라는 것이다.
    // 그렇다면 x개의 숫자로 이루어지는 경우를 보면,
    // 시작 숫자가 a라고 할때, a a+1 a+2 a+3 ~ a+(x-1) 규칙을 가진다.
    // 그러면 n - (1+2+~~+(x-1)) 후에 x로 나누어 떨어지면
    // x개의 숫자로 조합할 수 있다는 의미다.

    // 숫자 n 그 자체의 숫자 1개로도 하나의 조합이기 때문에
    // 무조건 1개로 시작한다.

    int answer = 1;
    
    for (int i = 1; (n - (i * (i + 1) / 2)) >= (i + 1); i++) {

        if ((n - (i * (i + 1) / 2)) % (i + 1) == 0)
            answer++;
    }

    return answer;
}

void service() {

    int n = 15;
    cout << solution(n) << endl;
}

숫자의_표현_END
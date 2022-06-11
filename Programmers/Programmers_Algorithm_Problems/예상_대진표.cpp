#include "예상_대진표.h"
#include <iostream>

using namespace std;

예상_대진표_BEGIN

int solution(int n, int a, int b)
{
    // 번호를 0번부터 시작하게 하면
    // 같은 단계에서는 /2의 몫이 같은 참가자끼리 대전.
    // 이긴 사람은 다음 단계에 번호는 /2의 몫이 된다.

    int answer = 1;

    a--;
    b--;

    while (a / 2 != b / 2) {
        a /= 2;
        b /= 2;
        answer++;
    }
    
    return answer;
}

void service() {

    cout << solution(8, 4, 7) << endl;
}

예상_대진표_END
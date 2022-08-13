#include "피보나치_수.h"
#include <iostream>

using namespace std;

피보나치_수_BEGIN

#define DIV_NUM 1234567

int solution(int n) {

    int answer = 0;

    int f0 = 0, f1 = 1;

    for (int i = 2; i <= n; i++) {
        answer = (f0 + f1) % DIV_NUM;
        f0 = f1;
        f1 = answer;
    }

    return answer;
}

void service() {

    int n = 3;
    cout << solution(n) << endl;
}

피보나치_수_END
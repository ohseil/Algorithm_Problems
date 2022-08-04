#include "숫자_블록.h"
#include <iostream>
#include <vector>

using namespace std;

숫자_블록_BEGIN

int getDivisor(long long num) {

    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0 && num / i <= 10000000)
            return num / i;
    }

    return -1;
}

vector<int> solution(long long begin, long long end) {

    // 위치 x에 마지막에 놓여지는 블록 번호는
    // 결국 놓여질 수 있는 블록 중 가장 큰 번호의 블록이다.
    // x의 약수들을 구해서
    // 가장 큰 블록 번호보다 작거나 같은 약수가 있다면 그 번호가 놓여질 블록 번호다.
    // 하지만 x가 소수라면 번호가 1인 블록 외에 놓여지는 블록이 없다는 것을 의미한다.

    vector<int> answer;

    if (begin == 1) {
        answer.push_back(0);
        begin++;
    }

    for (long long i = begin; i <= end; i++) {
        
        int n = getDivisor(i);

        if (n == -1)
            answer.push_back(1);
        else
            answer.push_back(n);
    }

    return answer;
}

void service() {

    long long begin = 1;
    long long end = 10;
    
    vector<int> ans = solution(begin, end);
    for (int a : ans)
        cout << a << " ";
    cout << endl;
}

숫자_블록_END
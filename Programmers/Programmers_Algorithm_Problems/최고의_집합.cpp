#include "최고의_집합.h"
#include <iostream>
#include <vector>

using namespace std;

최고의_집합_BEGIN

vector<int> solution(int n, int s) {
    
    // 우선 n개의 자연수로 s를 만들 수 없는 경우는,
    // 숫자 중복이 가능하기 때문에 n개의 1로 만들 수 없는 s < n 인 경우 밖에 없다.

    // 집합 중 원소들의 곱이 가장 큰 경우는 숫자 간 차이가 최소인 경우이다.
    // 따라서 s / n 을 기본 원소 x로 정하고 s % n을 (n-(s%n))개의 x에게 나눠서 더해준다.
    // 결국에는 집합이 {x,x, ..., x+1,x+1} 이런 형태로 나오게 될 것이다.

    if (s < n)
        return vector<int>({ -1 });

    vector<int> answer;
    
    int quotient = s / n;
    int remainder = s % n;

    for (int i = 0; i < n; i++) {
        if (i < n - remainder)
            answer.push_back(quotient);
        else
            answer.push_back(quotient + 1);
    }

    return answer;
}

void service() {

    int n = 2;
    int s = 9;

    vector<int> ans = solution(n, s);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

최고의_집합_END
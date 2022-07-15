#include "n^2_배열_자르기.h"
#include <iostream>
#include <vector>

using namespace std;

NN_배열_자르기_BEGIN

vector<int> solution(int n, long long left, long long right) {
    
    // 규칙을 찾아서 해결.

    vector<int> answer;

    for (long long i = left; i <= right; i++) {
        
        int row = i / n;
        int idx = i % n;

        answer.push_back((idx <= row) ? (row + 1) : (idx + 1));
    }

    return answer;
}

void service() {

    int n = 4;
    int left = 7;
    int right = 14;
    vector<int> ans = solution(n, left, right);
    
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

NN_배열_자르기_END
#include "최솟값_만들기.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

최솟값_만들기_BEGIN

int solution(vector<int> A, vector<int> B)
{
    // A와 B의 각 원소의 곱이 최소가 되는 경우는,
    // 하나의 배열에서는 큰 순서대로
    // 다른 배열에서는 작은 순서대로
    // 곱하는 경우가 최소가 된다.

    int answer = 0;

    int size = A.size();

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int i = 0; i < size; i++)
        answer += (A[i] * B[size - 1 - i]);

    return answer;
}

void service() {

    vector<int> a = { 1,4,2 };
    vector<int> b = { 5,4,4 };

    cout << solution(a, b) << endl;
}

최솟값_만들기_END
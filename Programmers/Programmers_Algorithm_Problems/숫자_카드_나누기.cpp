#include "숫자_카드_나누기.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

숫자_카드_나누기_BEGIN

vector<int>* findDivisors(int num) {

    vector<int>* divisors = new vector<int>();

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            divisors->push_back(i);
            divisors->push_back(num / i);
        }
    }
    
    divisors->push_back(num);

    return divisors;
}

bool canDivideAllElement(int divNum, vector<int>& arr) {
    for (int num : arr)
        if (num % divNum != 0)
            return false;
    return true;
}

bool cantDivideAllElement(int divNum, vector<int>& arr) {
    for (int num : arr)
        if (num % divNum == 0)
            return false;
    return true;
}

int findNumSatisfyConditions(vector<int>& divArr, vector<int>& nonDivArr) {

    vector<int>* divisors;

    sort(divArr.begin(), divArr.end());

    divisors = findDivisors(divArr[0]);
    sort(divisors->begin(), divisors->end(), greater<>());

    for (int divisor : *divisors) {

        if (canDivideAllElement(divisor, divArr) == true
            && cantDivideAllElement(divisor, nonDivArr) == true) {
            return divisor;
        }
    }

    return 0;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    
    // arrayA를 정렬해서 가장 작은 수 x를 찾는다.
    // x의 약수들을 구한다.
    // 모든 수들을 나눌 수 있어야 하기 때문에
    // 조건에 맞는 수는 구한 약수들에 포함 되어있어야 한다.
    // 구한 약수들을 큰 수부터 차례대로
    // arrayA의 모든 수를 나눠보고 arrayB의 모든 수를 나눠본다.
    // 조건을 처음 만족하는 수가 조건을 만족하는 가장 큰 수이다.

    // 이 과정을 arrayB를 기준으로 한번 더 실행한다.

    int answer = 0;
    int satisfyingNum;

    satisfyingNum = findNumSatisfyConditions(arrayA, arrayB);
    answer = (satisfyingNum > answer) ? satisfyingNum : answer;

    satisfyingNum = findNumSatisfyConditions(arrayB, arrayA);
    answer = (satisfyingNum > answer) ? satisfyingNum : answer;

    return answer;
}

void service() {

    vector<int> arrayA = { 10, 20 };
    vector<int> arrayB = { 5, 17 };

    cout << solution(arrayA, arrayB) << endl;
}

숫자_카드_나누기_END
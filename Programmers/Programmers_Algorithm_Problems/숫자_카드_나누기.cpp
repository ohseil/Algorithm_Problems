#include "����_ī��_������.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

����_ī��_������_BEGIN

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
    
    // arrayA�� �����ؼ� ���� ���� �� x�� ã�´�.
    // x�� ������� ���Ѵ�.
    // ��� ������ ���� �� �־�� �ϱ� ������
    // ���ǿ� �´� ���� ���� ����鿡 ���� �Ǿ��־�� �Ѵ�.
    // ���� ������� ū ������ ���ʴ��
    // arrayA�� ��� ���� �������� arrayB�� ��� ���� ��������.
    // ������ ó�� �����ϴ� ���� ������ �����ϴ� ���� ū ���̴�.

    // �� ������ arrayB�� �������� �ѹ� �� �����Ѵ�.

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

����_ī��_������_END
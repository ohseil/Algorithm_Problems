#include "N����_�ּҰ����.h"
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

N����_�ּҰ����_BEGIN

void factorization(int num, vector<int>& v) {
    
    unordered_map<int, int> countM;

    while (num > 1) {

        for (int i = 2; i <= num; i++) {
            if (num % i == 0) {
                num /= i;
                countM[i]++;
                break;
            }
        }
    }

    for (auto countInform : countM) {
        int n = countInform.first;
        int count = countInform.second;
        if (v[n] < count)
            v[n] = count;
    }
}

int solution(vector<int> arr) {
    
    // ���μ����ظ� ���� �ּ� ����� ���ϴ� ���� ���.

    int answer = 1;
    
    vector<int> countV(101, 0);

    for (int num : arr)
        factorization(num, countV);

    for (int num = 2; num <= 100; num++) {      
        while (countV[num]--) answer *= num;
    }

    return answer;
}

void service() {

    vector<int> arr = { 2,6,8,14 };
    cout << solution(arr) << endl;
}

N����_�ּҰ����_END
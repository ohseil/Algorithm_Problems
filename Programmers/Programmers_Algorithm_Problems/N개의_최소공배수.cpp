#include "N개의_최소공배수.h"
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

N개의_최소공배수_BEGIN

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
    
    // 소인수분해를 통한 최소 공배수 구하는 공식 사용.

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

N개의_최소공배수_END
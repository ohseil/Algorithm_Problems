#include "2개_이하로_다른_비트.h"
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

_2개_이하로_다른_비트_BEGIN

vector<long long> solution(vector<long long> numbers) {
    
    // 숫자를 비트로 표현했을 때 비트 값이 1인 자리 중 가장 높은 자리 x를 기준으로
    // 나머지 아래 자리의 숫자를 확인한다.
    // 이때 2가지 경우로 나뉜다.
    
    // 1. 아래 자리의 비트 값이 모두 1인 경우
    // 2. 아래 자리의 비트 값 중 최소 하나 이상이 0인 경우
    
    // 1번의 경우에는 x보다 하나 높은 자리의 비트를 0에서 1로 바꾼 후
    // x자리의 비트를 0으로 바꾼 숫자가 답이다.
    
    // 2번의 경우에는 비트 값이 0인 자리 중 가장 낮은 자리의 값을 1로 바꾼 후
    // 바꾼 자리보다 아래 자리에 1이 있다면 1을 0으로 바꾼 숫자가 답이다.

    vector<long long> answer;
    
    for (long long num : numbers) {
        
        bitset<64> bs(num);

        int one_idx = -1, zero_idx = -1;

        for (int i = 63; i >= 0; i--) {
            if (bs[i] == 1) {
                one_idx = i;
                break;
            }
        }

        for (int i = 0; i < one_idx; i++) {
            if (bs[i] == 0) {
                zero_idx = i;
                break;
            }
        }

        if (zero_idx == -1) {

            bs[one_idx + 1] = 1;
            bs[one_idx] = 0;
        }
        else {

            bs[zero_idx] = 1;
            
            if (zero_idx > 0)
                bs[zero_idx - 1] = 0;
        }

        answer.push_back((long long)bs.to_ullong());
    }

    return answer;
}

void service() {

    vector<long long> n = { 2,7 };
    vector<long long> ans = solution(n);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;

}

_2개_이하로_다른_비트_END
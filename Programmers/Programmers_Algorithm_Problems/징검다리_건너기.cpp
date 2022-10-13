#include "징검다리_건너기.h"
#include <iostream>
#include <vector>

using namespace std;

징검다리_건너기_BEGIN

#define MAX_PEOPLE 200000000

bool canCross(vector<int>& stones, int k, int crossCount) {

    int maxLength = 0;
    int zeroSequenceLength = 0;

    for (int stone : stones) {
        if (stone - crossCount < 0) {
            zeroSequenceLength++;
            if (zeroSequenceLength > maxLength)
                maxLength = zeroSequenceLength;
        }
        else
            zeroSequenceLength = 0;
    }

    return maxLength < k;
}

int solution(vector<int> stones, int k) {
    
    // 이분 탐색 사용.
    // 건널 수 있는 최대 친구 수를 찾는다.
    // 검사 내용은,
    // 건너는 친구 수 x가 건넌다고 가정할 때,
    // 징검다리를 순회하면서 돌의 밟을 수 있는 숫자에서 x를 뺐을 때,
    // 0이 되는 돌이 최대 얼마나 연속되는지 찾는다.
    // 연속되는 최대 숫자가 k 이하라면 x명이 건널 수 있다는 의미다.

    // 여기서 연속되는 최대 숫자가 k가 포함되는 이유는,
    // 돌을 밟은 직후 정확하게 0이 되는 경우만 세기 때문에,
    // 결국 x명이 지나간 직후에 연속되는 개수가 k개가 되는 것이기 때문에
    // 건널 수 있는 것으로 볼 수 있다.

    int answer = 0;

    int start = 1, end = MAX_PEOPLE, mid;

    while (start <= end) {

        mid = (start + end) / 2;

        if (canCross(stones, k, mid) == true) {
            start = mid + 1;
            if (answer < mid)
                answer = mid;
        }
        else {
            end = mid - 1;
        }
    }

    return answer;
}

void service() {

    vector<int> stones = { 2, 4, 5, 3, 2, 1, 5, 2, 5, 1 };
    int k = 3;

    cout << solution(stones, k) << endl;
}

징검다리_건너기_END
#include "스티커_모으기2.h"
#include <iostream>
#include <vector>

using namespace std;

스티커_모으기2_BEGIN

int solution(vector<int> sticker)
{

    // dp를 사용한다.
    // 기본적으로는 dp[i] = max(dp[i - 1] + sticker[i], dp[i - 2]) 이다.
    // 하지만 첫 번째 스티커의 상태가 마지막 스티커의 상태에 영향을 미친다.
    // 때문에 첫 번째 스티커를 뗐을 때와 안 뗐을 때를 구분해서 2번 진행한다.

    int answer = 0;

    int size = sticker.size();

    if (size == 1)
        return sticker[0];

    vector<int> dp1(size), dp2(size);

    dp1[0] = 0;
    dp1[1] = sticker[1];
    dp2[0] = sticker[0];
    dp2[1] = max(sticker[0], sticker[1]);

    for (int i = 2; i < size; i++) {
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + sticker[i]);
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + sticker[i]);
    }

    answer = max(dp1[size - 1], dp2[size - 2]);

    return answer;
}

void service() {

    vector<int> stickers = { 1,3,2,5,4 };

    cout << solution(stickers) << endl;
}

스티커_모으기2_END
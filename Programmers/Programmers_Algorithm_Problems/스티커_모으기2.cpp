#include "��ƼĿ_������2.h"
#include <iostream>
#include <vector>

using namespace std;

��ƼĿ_������2_BEGIN

int solution(vector<int> sticker)
{

    // dp�� ����Ѵ�.
    // �⺻�����δ� dp[i] = max(dp[i - 1] + sticker[i], dp[i - 2]) �̴�.
    // ������ ù ��° ��ƼĿ�� ���°� ������ ��ƼĿ�� ���¿� ������ ��ģ��.
    // ������ ù ��° ��ƼĿ�� ���� ���� �� ���� ���� �����ؼ� 2�� �����Ѵ�.

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

��ƼĿ_������2_END
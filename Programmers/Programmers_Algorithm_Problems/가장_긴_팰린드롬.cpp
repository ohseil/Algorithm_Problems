#include "가장_긴_팰린드롬.h"
#include <iostream>

using namespace std;

가장_긴_팰린드롬_BEGIN

int solution(string s)
{
    // 각 위치의 문자를 기준으로 양 옆으로 범위를 키우면서 탐색한다.
    // 2가지 경우가 있는데 홀수 개인 경우와 짝수 개인 경우다.
    // 홀수 개는 하나의 문자를 기준으로 양 옆으로 탐색한다.
    // 짝수 개는 2개의 같은 문자를 기준으로 양 옆으로 탐색한다.
    // 시간복잡도가 O(n^2)이지만 문자열의 길이가 최대 2500이기 때문에 상관없다.
    
    int answer = 0;
    int len = s.length();

    // 홀수 개의 문자를 포함한 팰린드롬
    for (int i = 0; i < len; i++) {

        int stand = i;
        int dist = 1;
        int count = 1;

        while (stand - dist >= 0 &&
            stand + dist < len &&
            s[stand - dist] == s[stand + dist]) {

            dist++;
            count += 2;
        }

        if (answer < count)
            answer = count;
    }

    // 짝수 개의 문자를 포함한 팰린드롬
    for (int i = 0; i < len - 1; i++) {

        if (s[i] != s[i + 1])
            continue;

        int stand1 = i, stand2 = i + 1;
        int dist = 1;
        int count = 2;

        while (stand1 - dist >= 0 &&
            stand2 + dist < len &&
            s[stand1 - dist] == s[stand2 + dist]) {

            dist++;
            count += 2;
        }

        if (answer < count)
            answer = count;
    }

    return answer;
}

void service() {

    string s = "abcdcba";
    cout << solution(s) << endl;
}

가장_긴_팰린드롬_END
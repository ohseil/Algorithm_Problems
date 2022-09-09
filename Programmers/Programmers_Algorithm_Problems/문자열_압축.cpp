#include "문자열_압축.h"
#include <iostream>
#include <string>

using namespace std;

문자열_압축_BEGIN

int solution(string s) {
    
    // 모든 경우를 탐색한다.
    // 1개씩부터 시작해서 (s.length() / 2)개씩까지 압축해본다.
    // s.length() / 2 보다 크게 자르는 것은
    // 같은 길이가 2개 이상 나오지 않기 때문에 의미 없다.

    int answer = s.length();
    
    for (int divLen = 1; divLen <= s.length() / 2; divLen++) {

        int totalLen = 0;

        string curFindString = s.substr(0, divLen);
        int sameCount = 1;

        int idx = divLen;

        while (idx <= (s.length() - divLen)) {

            string str = s.substr(idx, divLen);

            if (str == curFindString) {
                sameCount++;
            }
            else {
                if (sameCount > 1) totalLen += to_string(sameCount).length();
                totalLen += curFindString.length();
                curFindString = str;
                sameCount = 1;
            }

            idx += divLen;
        }

        if (sameCount > 1) totalLen += to_string(sameCount).length();
        totalLen += curFindString.length();

        if (idx < s.length())
            totalLen += (s.length() - idx);

        if (totalLen < answer)
            answer = totalLen;
    }

    return answer;
}

void service() {

    string s = "abcabcabcabcdededededede";
    cout << solution(s) << endl;
}

문자열_압축_END
#include "k진수에서_소수_개수_구하기.h"
#include <iostream>
#include <string>

using namespace std;

k진수에서_소수_개수_구하기_BEGIN

bool isPrime(long long num) {
    
    if (num == 1)
        return false;

    for (long long i = 2; i * i <= num; i++)
        if (num % i == 0)
            return false;

    return true;
}

int solution(int n, int k) {

    // '0'을 기준으로 나눠진 숫자들의 소수 여부 확인

    int answer = 0;

    string str = "";

    while (n != 0) {
        str = to_string(n % k) + str;
        n /= k;
    }

    while (str.empty() == false) {

        int idx = str.find("0");
        
        if (0 <= idx && idx < str.length()) {
            // 0 있음
            if (idx > 0) {
                if (isPrime(stoll(str.substr(0, idx))) == true)
                    answer++;
            }

            str = str.substr(idx + 1);
        }
        else {
            // 0 없음
            if (str.length() > 0) {
                if (isPrime(stoll(str)) == true)
                    answer++;
            }

            break;
        }
    }

    return answer;
}

void service() {

    int n = 437674;
    int k = 3;
    cout << solution(n, k) << endl;

}

k진수에서_소수_개수_구하기_END
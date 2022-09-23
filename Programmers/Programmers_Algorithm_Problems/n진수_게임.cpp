#include "n진수_게임.h"
#include <iostream>
#include <string>

using namespace std;

n진수_게임_BEGIN

char baseNums[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

string getNumByBasenum(int num, int n) {

    string result = "";

    do {

        result = baseNums[num % n] + result;
        num /= n;

    } while (num != 0);

    return result;
}

string solution(int n, int t, int m, int p) {
    
    // 게임에서 사용되는 숫자를 num이라고 하고, 턴을 turn이라고 하자.
    // num = 0, turn = 0으로 초기화를 하고 턴 계산을 위해 p--를 한 상태로 계산했다.
    // num을 하나씩 증가시키면서 차례대로 확인했다.
    // num을 n진법의 string으로 바꾼 후,
    // string의 길이만큼 문자를 확인하면서 turn을 계산했다.
    
    // n진법으로 바꾸는 방법은 기본적인 n진수 계산 방법을 사용했다.
    // 그리고 10진법 이상의 문자가 들어가는 계산을 위해서 배열을 만들어서 사용했다.
    // 배열을 하나 만들어 n을 index로 한 위치의 값을 n진수에서 각 자리수가 넘어가는 숫자로 저장했다.
    // 10 ~ 16진법은 A ~ F로 저장했다.
    
    // 현재 turn이 player의 턴인지 확인하는 방법은 (turn%m == p)이면 player의 턴이다.

    string answer = "";
    
    int num = 0;
    int turn = 0;
    p--;

    while (answer.length() < t) {

        string str = getNumByBasenum(num, n);

        for (int i = 0; i < str.length(); i++) {

            if (turn % m == p) {

                answer.push_back(str[i]);

                if (answer.length() == t)
                    break;
            }

            turn++;
        }

        num++;
    }

    return answer;
}

void service() {

    int n = 2;
    int t = 4;
    int m = 2;
    int p = 1;

    cout << solution(n, t, m, p) << endl;
}

n진수_게임_END
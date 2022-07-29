#include "다음_큰_숫자.h"
#include <iostream>
#include <bitset>

using namespace std;

다음_큰_숫자_BEGIN

int solution(int n) {
    
    // 단순하게 1씩 증가시키면서 확인한다.
    // 생각해 보면, 어차피 n과 같은 1의 개수를 가진 숫자까지 증가시키는 횟수는 얼마 안된다.
    // 비교 방법은 bitset을 사용한다.
    // int 형이므로 bitset의 사용 bit 개수를 32개로 설정하고 n의 bit 1의 개수를 저장해놓는다.
    // bitset의 count() 함수를 사용하면 바로 구할 수 있다.
    // bit 1의 개수가 같은 숫자가 나올때까지 1씩 증가시킨다.

    int answer = n + 1;

    int origin_count = bitset<32>(n).count();

    while (bitset<32>(answer).count() != origin_count) answer++;

    return answer;
}

void service() {

    int n = 5;
    cout << solution(n) << endl;

}

다음_큰_숫자_END
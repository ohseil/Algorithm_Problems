#include "멀쩡한_사각형.h"
#include <iostream>

using namespace std;

멀쩡한_사각형_BEGIN

long long findGCD(int a, int b) {
	if (a % b == 0) return b;
	else return findGCD(b, a % b);
}

long long solution(int w, int h) {
	
	// 규칙을 찾아보면,
	// 일정 크기의 사각형으로 나눴을 때,
	// 사용하지 못하는 사각형의 개수가 여러 개 이어져 있는 형태다.
	// 나눠지는 크기는 최소 크기로 나눠야 하는데
	// 이것은 w와 h의 최대공약수인 x개로 나눴을 때다.
	
	// 최소 크기의 직사각형의 w와 h를 minW, minH라고 할때,
	// 최소 크기의 직사각형에서 포함되어 있는 사용하지 못하는 사각형 개수는
	// minW + minH - 1이다.

	// 사용 가능한 사각형 개수는 w * h - (minW + minH - 1) * x가 된다.

	long long answer = 1;
	
	long long gcdNum = findGCD(w, h);

	int minW = w / gcdNum;
	int minH = h / gcdNum;
	
	int unavailableCount = (minW + minH - 1) * gcdNum;

	answer = (long long)w * h - unavailableCount;

	return answer;
}

void service() {

	int w = 8;
	int h = 12;

	cout << solution(w, h) << endl;
}

멀쩡한_사각형_END
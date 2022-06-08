#include "조이스틱.h"

int 조이스틱::solution(string name) {

	// 무조건 모든 'A'가 아닌 알파벳은 변경해야 하기 때문에
	// 나중에 모든 알파벳을 확인해서 계산하여 필요한 조이스틱 움직임 횟수 +.
	
	// 고려할 수 있는 순회 경로를 살펴보면
	// 'A'가 아닌 알파벳을 B라고 한다면 B들의 위치는 무조건 다 들려야 한다.
	// 1. 처음부터 끝까지 순회하는 방법
	// 2. 처음 위치 -> 중간의 B -> 처음 위치 -> 마지막 위치 -> 중간의 B 이후에 처음 나오는 B
	// 3. 처음 위치 -> 마지막 위치 -> 중간의 B 이후에 처음 나오는 B -> 마지막 위치 -> 처음 위치 -> 중간의 B
	// 3가지 경로 중 가장 작은 이동 횟수의 경로가 답이다.

	int answer = 0;

	int len = name.length();
	int cost = name.length();

	for (int i = 0; i < len; i++) {

		if (name[i] == 'A')
			continue;

		int idx = 0;

		for (int j = i + 1; j < len; j++) {
			if (name[j] != 'A') {
				idx = j;
				break;
			}
		}

		if (idx != 0)
			idx = len - idx;

		cost = min(cost, min(2 * i + idx, i + 2 * idx));
	}

	if (cost == name.length())
		cost = 0;

	answer = (len - 1 < cost) ? (len - 1) : cost;

	for (char ch : name)
		answer += (ch - 'A' < 'Z' - ch + 1) ? (ch - 'A') : ('Z' - ch + 1);

	return answer;
}



void 조이스틱::service() {

    string str = "AAAAA";
    cout << solution(str) << endl;
}
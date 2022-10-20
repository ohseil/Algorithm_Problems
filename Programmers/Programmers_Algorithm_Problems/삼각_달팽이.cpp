#include "삼각_달팽이.h"
#include <iostream>
#include <vector>

using namespace std;

삼각_달팽이_BEGIN

int maxNum;

int num;
int dif;
int pos;

void init(vector<int>& pyramid, int n) {
    
    maxNum = (n * (n + 1) / 2);

    // padding
    pyramid.assign((n + 1) * (n + 2) / 2 + 1, 0);
    for (int i = (n * (n + 1) / 2) + 1; i < pyramid.size(); i++)
        pyramid[i] = -1;

    pyramid[1] = 1;
    num = 2;
    dif = 1;
    pos = 1;
}

void fillLeftMoving(vector<int>& pyramid) {
	while (pyramid[pos + dif] == 0) {
        pos += dif;
        pyramid[pos] = num;
        num++;
        dif++;
    }
}

void fillBottomMoving(vector<int>& pyramid) {
	while (pyramid[pos + 1] == 0) {
        pos++;
        pyramid[pos] = num;
        num++;
    }
}

void fillRightMoving(vector<int>& pyramid) {
	while (pyramid[pos - dif] == 0) {
        pos -= dif;
        pyramid[pos] = num;
        num++;
        dif--;
    }
}

vector<int> solution(int n) {
    
    // 숫자를 채워넣는 규칙을 찾는다.
    // 1. 왼쪽 대각선 따라 이동
    // 2. 아래쪽 따라 이동
    // 3. 오른쪽 대각선 따라 이동
    // 이 순서대로 이동하면서 숫자를 채워넣는다.
    // 이동 방향이 바뀌는 기준은 범위를 벗어나거나 이미 채워져 있는 경우다.

    // 1차원 배열을 사용한다.
    
    // 왼쪽 대각선을 따라 이동할 때는 index가 dif만큼 증가하는데,
    // dif는 한 층 내려갈 때마다 1씩 증가한다.

    // 아래쪽을 따라 이동할 때는 단순히 index가 +1씩 증가한다.
    
    // 오른쪽 대각선을 따라 이동할 때는 왼쪽 대각선을 따라 마지막 이동했을 때의 dif 값을 기준으로
    // index가 dif만큼 감소한다.
    // dif는 한 층 올라갈 때마다 1씩 감소한다.

    // (n * (n + 1) / 2) 숫자까지 채워지면 종료한다.

    vector<int> answer;
    
    vector<int> pyramid;

    init(pyramid, n);

	while (num <= maxNum) {
		fillLeftMoving(pyramid);
		fillBottomMoving(pyramid);
		fillRightMoving(pyramid);
	}

    for (int i = 1; i <= maxNum; i++)
        answer.push_back(pyramid[i]);

    return answer;
}

void service() {

    int n = 4;
    
    vector<int> ans = solution(n);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

삼각_달팽이_END
#include "하노이의_탑.h"
#include <iostream>
#include <vector>

using namespace std;

하노이의_탑_BEGIN

// n개의 원판을 from부터 to까지 옮기는 함수
void hanoi(int n, int from, int to, vector<vector<int>>& ans) {

    if (n == 0) {
        return;
    }

    int restCol = 1;

    for (int col = 1; col <= 3; col++)
        if (col != from && col != to) {
            restCol = col;
            break;
        }

    hanoi(n - 1, from, restCol, ans);
    ans.emplace_back(vector<int>({ from, to }));
    hanoi(n - 1, restCol, to, ans);
    
}

vector<vector<int>> solution(int n) {
    
    // n번째 원판을 기둥3으로 옮기기 위해서는
    // n-1개의 원판을 기둥2로 옮긴 후 n번째 원판을 옮기고
    // 다시 n-1개의 원판을 기둥3으로 옮겨야 한다.

    // 이 과정에서 n-1번째 원판을 또 기둥 2로 옮기기 위해서
    // n-2개의 원판을 기둥3으로 옮긴 후 n-1번째 원판을 옮기고
    // 다시 n-2개의 원판을 기둥2로 옮겨야 한다.

    // 이런 식으로 재귀적으로 진행되도록 설계한다면,
    // hanoi(n, from, to) : n개의 원판을 from부터 to까지 옮기는 함수
    // 로 정의한다면,
    // hanoi(n, from, to) 내부 로직에서는 from과 to가 아닌 기둥을 x라고 할 때,
    // 1. hanoi(n - 1, from, x)
    // 2. n번째 원판 from -> x 이동
    // 3. hanoi(n - 1, x, to)
    // 과정으로 설계할 수 있다.

    vector<vector<int>> answer;
    
    hanoi(n, 1, 3, answer);

    return answer;
}

void service() {

    int n = 2;

    vector<vector<int>> ans = solution(n);
    for (auto a : ans)
        cout << a[0] << "->" << a[1] << " ";
    cout << endl;
}

하노이의_탑_END
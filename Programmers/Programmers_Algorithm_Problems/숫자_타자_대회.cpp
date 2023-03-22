#include "숫자_타자_대회.h"
#include <iostream>
#include <limits.h>
#include <unordered_map>

using namespace std;

숫자_타자_대회_BEGIN

#define HashMap unordered_map

// costs[a][b] = 숫자 키 a에서 숫자 키 b까지 이동 시 최소 비용
int costs[10][10] = { 1, 7, 6, 7, 5, 4, 5, 3, 2, 3,
                      7, 1, 2, 4, 2, 3, 5, 4, 5, 6,
                      6, 2, 1, 2, 3, 2, 3, 5, 4, 5,
                      7, 4, 2, 1, 5, 3, 2, 6, 5, 4,
                      5, 2, 3, 5, 1, 2, 4, 2, 3, 5,
                      4, 3, 2, 3, 2, 1, 2, 3, 2, 3,
                      5, 5, 3, 2, 4, 2, 1, 5, 3, 2,
                      3, 4, 5, 6, 2, 3, 5, 1, 2, 4,
                      2, 5, 4, 5, 3, 2, 3, 2, 1, 2,
                      3, 6, 5, 4, 5, 3, 2, 4, 2, 1 };

bool canMove(HashMap<int, HashMap<int, int>>& hmapCurTypingData, int lFinger, int rFinger, int cost) {
    return (hmapCurTypingData.count(lFinger) == 0
        || hmapCurTypingData[lFinger].count(rFinger) == 0
        || hmapCurTypingData[lFinger][rFinger] > cost);
}

int solution(string numbers) {

    // 기본 알고리즘은 bfs다.
    // 각 상태 값은 왼쪽 엄지 위치, 오른쪽 엄지 위치, 현재까지의 총 비용이다.
    // 해당 데이터를 가지고 탐색을 진행한다.

    // 각 숫자마다 queue에 있는 data를 모두 꺼내서 확인하는 방식인데,
    // 여기서는 queue 대신 hash map을 사용했다.
    // 이유는 불가능한 경로를 제거해 주기 위해서다.
    // 같은 숫자를 누르는 과정에서 같은 손가락의 위치를 가진 경로의 총 비용이 다르다면,
    // 가장 비용이 적은 경로만 남기고 제거해 줘야한다.
    // hash map을 통해서 각 숫자 탐색마다 불가능한 경로를 제거해 준다.

    // hash map에 저장 된 경로들을 다음 숫자 탐색에 사용한다.

    // 각 경로를 탐색하는 조건은 다음과 같다.
    // 1. if (눌러야 하는 숫자 == 왼쪽 엄지 위치의 숫자) 경로가 하나다.
    // 2. if (눌러야 하는 숫자 == 오른쪽 엄지 위치의 숫자) 경로가 하나다.
    // 3. 왼쪽 엄지로 누르는 경우와 오른쪽 엄지로 누르는 경우 2가지 경로가 있다.
    // 각 다음 경로마다 같은 손가락 위치의 경로의 비용을 확인해서 불가능한 경로는 더 이상 진행하지 않는다.

    int answer = INT_MAX;

    HashMap<int, HashMap<int, int>> hmapTypingCostAndFingerPos; // <left, <right, cost>>

    hmapTypingCostAndFingerPos[4][6] = 0;

    for (int i = 0; i < numbers.length(); i++) {

        int num = numbers[i] - 48;
        HashMap<int, HashMap<int, int>> hmapCurTypingCostAndFingerPos;

        for (auto typingData : hmapTypingCostAndFingerPos) {
            for (auto rFingerAndCost : typingData.second) {

                int lFinger = typingData.first;
                int rFinger = rFingerAndCost.first;
                int totalCost = rFingerAndCost.second;

                if (num == lFinger) {
                    if (canMove(hmapCurTypingCostAndFingerPos, num, rFinger, totalCost + 1) == true)
                        hmapCurTypingCostAndFingerPos[num][rFinger] = totalCost + 1;
                }
                else if (num == rFinger) {
                    if (canMove(hmapCurTypingCostAndFingerPos, lFinger, num, totalCost + 1) == true)
                        hmapCurTypingCostAndFingerPos[lFinger][num] = totalCost + 1;
                }
                else {
                    if (canMove(hmapCurTypingCostAndFingerPos, num, rFinger, totalCost + costs[lFinger][num]) == true)
                        hmapCurTypingCostAndFingerPos[num][rFinger] = totalCost + costs[lFinger][num];
                    if (canMove(hmapCurTypingCostAndFingerPos, lFinger, num, totalCost + costs[rFinger][num]) == true)
                        hmapCurTypingCostAndFingerPos[lFinger][num] = totalCost + costs[rFinger][num];
                }

            }
        }

        hmapTypingCostAndFingerPos = hmapCurTypingCostAndFingerPos;
    }

    for (auto typingData : hmapTypingCostAndFingerPos) {
        for (auto rFingerAndCost : typingData.second) {
            int totalCost = rFingerAndCost.second;
            if (answer > totalCost)
                answer = totalCost;
        }
    }

    return answer;
}

void service() {

    string number = "1756";

    cout << solution(number) << endl;
}

숫자_타자_대회_END
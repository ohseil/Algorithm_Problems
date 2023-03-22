#include "����_Ÿ��_��ȸ.h"
#include <iostream>
#include <limits.h>
#include <unordered_map>

using namespace std;

����_Ÿ��_��ȸ_BEGIN

#define HashMap unordered_map

// costs[a][b] = ���� Ű a���� ���� Ű b���� �̵� �� �ּ� ���
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

    // �⺻ �˰����� bfs��.
    // �� ���� ���� ���� ���� ��ġ, ������ ���� ��ġ, ��������� �� ����̴�.
    // �ش� �����͸� ������ Ž���� �����Ѵ�.

    // �� ���ڸ��� queue�� �ִ� data�� ��� ������ Ȯ���ϴ� ����ε�,
    // ���⼭�� queue ��� hash map�� ����ߴ�.
    // ������ �Ұ����� ��θ� ������ �ֱ� ���ؼ���.
    // ���� ���ڸ� ������ �������� ���� �հ����� ��ġ�� ���� ����� �� ����� �ٸ��ٸ�,
    // ���� ����� ���� ��θ� ����� ������ ����Ѵ�.
    // hash map�� ���ؼ� �� ���� Ž������ �Ұ����� ��θ� ������ �ش�.

    // hash map�� ���� �� ��ε��� ���� ���� Ž���� ����Ѵ�.

    // �� ��θ� Ž���ϴ� ������ ������ ����.
    // 1. if (������ �ϴ� ���� == ���� ���� ��ġ�� ����) ��ΰ� �ϳ���.
    // 2. if (������ �ϴ� ���� == ������ ���� ��ġ�� ����) ��ΰ� �ϳ���.
    // 3. ���� ������ ������ ���� ������ ������ ������ ��� 2���� ��ΰ� �ִ�.
    // �� ���� ��θ��� ���� �հ��� ��ġ�� ����� ����� Ȯ���ؼ� �Ұ����� ��δ� �� �̻� �������� �ʴ´�.

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

����_Ÿ��_��ȸ_END
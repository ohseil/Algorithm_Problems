#include "�ٸ���_������_Ʈ��.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

�ٸ���_������_Ʈ��_BEGIN

#define MAX_TIME 100010001

int solution(int bridge_length, int weight, vector<int> truck_weights) {

    int answer = 0;

    int cur_b_weight = 0;
    int cur_t_count = 0;
    int crossed_count = 0;

    queue<pair<int, int>> bridge;
    queue<int> wait_q;

    for (int truck : truck_weights)
        wait_q.push(truck);

    for (int i = 1; i <= MAX_TIME; i++) {

        if (bridge.empty() == false) {
            // ���� Ʈ�� Ȯ�� �� ó��

            pair<int, int> truck = bridge.front();

            if (truck.first + bridge_length <= i) {
                bridge.pop();
                cur_b_weight -= truck.second;
                cur_t_count--;
                crossed_count++;
            }
        }

        if (wait_q.empty() == false) {
            // Ʈ�� �ٸ��� �ø��� 

            int t_weight = wait_q.front();

            if (cur_t_count < bridge_length && t_weight + cur_b_weight <= weight) {

                bridge.push({ i, t_weight });
                cur_b_weight += t_weight;
                cur_t_count++;
                wait_q.pop();
            }
        }

        if (bridge.empty() == true && wait_q.empty() == true) {
            answer = i;
            break;
        }
    }

    return answer;
}


void service() {

    int bl = 2;
    int w = 10;
    vector<int> tw = { 7,4,5,6 };
    cout << solution(bl, w, tw) << endl;
}

�ٸ���_������_Ʈ��_END
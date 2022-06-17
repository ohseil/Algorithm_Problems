#include "다리를_지나는_트럭.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

다리를_지나는_트럭_BEGIN

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
            // 내릴 트럭 확인 후 처리

            pair<int, int> truck = bridge.front();

            if (truck.first + bridge_length <= i) {
                bridge.pop();
                cur_b_weight -= truck.second;
                cur_t_count--;
                crossed_count++;
            }
        }

        if (wait_q.empty() == false) {
            // 트럭 다리에 올리기 

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

다리를_지나는_트럭_END
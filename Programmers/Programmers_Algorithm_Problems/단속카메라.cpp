#include "단속카메라.h"
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

단속카메라_BEGIN

int solution(vector<vector<int>> routes) {
    
    // 고속도로에 아무 차도 없는 상태에서 차가 들어왔을 때,
    // 카메라 작동을 시작한다고 생각한다.
    // 카메라가 작동을 시작한 후에 진입한 차들은
    // 같은 카메라로 촬영이 가능하다.
    // 카메라 작동 시작한 후 진입한 차들 중 하나라도 나간다면,
    // 카메라는 종료한다. 여기까지가 카메라 한대로 촬영할 수 있는 차들이다.
    // 카메라 종료 후에 이전에 진입한 차들이 나가도 신경 쓸 필요 없다.
    
    // 카메라 종료 후에 다시 새로 진입한 차가 생기면 다시 카메라를 작동한다.
    // 위의 작업을 반복한다.
    // 단, 새 카메라 작동 전에 진입했던 차들이 진출하는 경우를 고려해야 한다.

    int answer = 0;
    
    // <시간, <진출or진입 flag, 차번호list>
    map<int, map<int, vector<int>>> time_m;

    for (int i = 0; i < routes.size(); i++) {
        time_m[routes[i][0]][0].push_back(i);
        time_m[routes[i][1]][1].push_back(i);
    }

    vector<int> car_v;
    set<int> car_s;
    bool onCamera = false;

    for (auto t_data : time_m) {

        for (auto data : t_data.second) {

            int flag = data.first;

            if (flag == 0) {
                // 진입
                for (int car : data.second) {

                    if (onCamera == false) {
                        
                        onCamera = true;
                        answer++;
                    }
                    
                    car_v.push_back(car);
                }
            }
            else {
                // 진출
                for (int car : data.second) {

                    if (car_s.count(car) == 0) {

                        for (int num : car_v)
                            car_s.insert(num);

                        car_v.clear();

                        onCamera = false;
                    }

                }
            }

        }
    }

    return answer;
}

void service() {

    vector<vector<int>> r = { {-20,-15},{-14,-5},{-18,-13},{-5,-3} };
    cout << solution(r) << endl;
}

단속카메라_END
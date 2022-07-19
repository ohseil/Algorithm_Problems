#include "�ܼ�ī�޶�.h"
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

�ܼ�ī�޶�_BEGIN

int solution(vector<vector<int>> routes) {
    
    // ��ӵ��ο� �ƹ� ���� ���� ���¿��� ���� ������ ��,
    // ī�޶� �۵��� �����Ѵٰ� �����Ѵ�.
    // ī�޶� �۵��� ������ �Ŀ� ������ ������
    // ���� ī�޶�� �Կ��� �����ϴ�.
    // ī�޶� �۵� ������ �� ������ ���� �� �ϳ��� �����ٸ�,
    // ī�޶�� �����Ѵ�. ��������� ī�޶� �Ѵ�� �Կ��� �� �ִ� �����̴�.
    // ī�޶� ���� �Ŀ� ������ ������ ������ ������ �Ű� �� �ʿ� ����.
    
    // ī�޶� ���� �Ŀ� �ٽ� ���� ������ ���� ����� �ٽ� ī�޶� �۵��Ѵ�.
    // ���� �۾��� �ݺ��Ѵ�.
    // ��, �� ī�޶� �۵� ���� �����ߴ� ������ �����ϴ� ��츦 ����ؾ� �Ѵ�.

    int answer = 0;
    
    // <�ð�, <����or���� flag, ����ȣlist>
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
                // ����
                for (int car : data.second) {

                    if (onCamera == false) {
                        
                        onCamera = true;
                        answer++;
                    }
                    
                    car_v.push_back(car);
                }
            }
            else {
                // ����
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

�ܼ�ī�޶�_END
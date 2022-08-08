#include "����_���_���.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

����_���_���_BEGIN

int timeTomin(string t) {
    return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3));
}

vector<int> solution(vector<int> fees, vector<string> records) {
    
    // map�� ����� �ڵ������� ���� ���� �ð��� �����Ѵ�.
    // map�� �� �ϳ� ����� �ֱ� ����� �������� �������� ���ο�
    // ������� ���� �ð��� �����Ѵ�.
    // ������ ��� ������ ���� ���� �ð��� ����ؼ� ���� ���� �ð��� �߰��Ѵ�.
    // ��� record�� ��ȸ �� ���� ��ϸ� �ִ� �ڵ����� ���� �ð��� 23:59�� �Ͽ� ����Ѵ�.

    // map�� ����, ���� �� key�� �������� ���� ���� ���ĵǾ� �ִ�.
    // ���� ���� �ð��� ������ map�� ��ȸ�Ͽ� ����� ����Ѵ�.

    vector<int> answer;
    
    map<int, int> timeM;
    map<int, pair<string, int>> parkM;

    for (string record : records) {

        int min, car;
        string park;

        min = timeTomin(record.substr(0, 5));
        car = stoi(record.substr(6, 4));
        park = record.substr(11);

        if (park == "IN") {
            parkM[car] = { park, min };
        }
        else {

            int inTime = parkM[car].second;
            timeM[car] += (min - inTime);
            parkM[car] = { park, -1 };
        }
    }

    for (auto carInform : parkM) {
        if (carInform.second.first == "IN")
            timeM[carInform.first] += timeTomin("23:59") - carInform.second.second;
    }

    for (auto carInform : timeM) {
        
        int time = carInform.second;
        int totalFee = 0;

        if (time < fees[0]) {
            totalFee = fees[1];
        }
        else {

            totalFee += fees[1];
            time -= fees[0];
        
            if (time > 0) {
                totalFee += (time / fees[2]) * fees[3];

                if (time % fees[2] != 0)
                    totalFee += fees[3];
            }
        }

        answer.push_back(totalFee);
    }

    return answer;
}

void service() {

    vector<int> fees = { 180,5000,10,600 };
    vector<string> records = { "05:34 5961 IN", "06:00 0000 IN",
        "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN",
        "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };

    vector<int> ans = solution(fees, records);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

����_���_���_END
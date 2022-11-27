#include "��_����.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

��_����_BEGIN

#define HashMap unordered_map

class Tangerine {
public:
    int kinds;
    int num;
    Tangerine(int kinds, int num) : kinds(kinds), num(num) {}
    static bool cmp(Tangerine lhs, Tangerine rhs) {
        if (lhs.num > rhs.num) return true;
        return false;
    }
};

HashMap<int, int> numOfTangerinesPerKindsMap;
vector<Tangerine> tangerineList;

void countNumOfTangerinesPerKinds(vector<int>& kindsOfTangerineList) {
    for (int kindsOfTangerine : kindsOfTangerineList) {
        numOfTangerinesPerKindsMap[kindsOfTangerine]++;
    }
}

void makeTangerineList() {
    for (auto numOfTangerinesPerKind : numOfTangerinesPerKindsMap) {
        int kindsOfTangerine = numOfTangerinesPerKind.first;
        int numOfTangerine = numOfTangerinesPerKind.second;
        tangerineList.push_back(Tangerine(kindsOfTangerine, numOfTangerine));
    }
}

int getMinNumOfKinsByPickingTangerines(int needNumOfTangerine) {

    int numOfKinds = 0;

    sort(tangerineList.begin(), tangerineList.end(), Tangerine::cmp);

    for (Tangerine tangerine : tangerineList) {

        if (needNumOfTangerine <= 0)
            break;

        int numOfTangerine = numOfTangerinesPerKindsMap[tangerine.kinds];

        numOfKinds++;
        needNumOfTangerine -= numOfTangerine;
    }

    return numOfKinds;
}

int solution(int k, vector<int> tangerine) {
    
    // ���� ���� ������ ���� ���� ���ؼ���,   
    // ���� ���� ������ ���� �������� ���� �ȴ�.

    int answer = 0;
    
    countNumOfTangerinesPerKinds(tangerine);
    makeTangerineList();

    answer = getMinNumOfKinsByPickingTangerines(k);

    return answer;
}

void service() {

    int k = 6;
    vector<int> tangerines = { 1, 3, 2, 5, 4, 5, 2, 3 };

    int answer = solution(k, tangerines);
    cout << answer << endl;
}

��_����_END
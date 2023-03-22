#include "������ũ_�ڸ���.h"
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

������ũ_�ڸ���_BEGIN

#define HashMap unordered_map

class Rollcake {

private:

    HashMap<int, int> toppingMap;

public:

    void addTopping(const int toppingType) {
        toppingMap[toppingType]++;
    }

    void removeTopping(const int toppingType) {

        toppingMap[toppingType]--;

        if (toppingMap[toppingType] <= 0)
            toppingMap.erase(toppingType);

    }

    int getNumOfToppingTypes() {
        return toppingMap.size();
    }

};

Rollcake leftPiece;
Rollcake rightPiece;

void makeInitRollcake(vector<int>& toppings) {
    for (int toppingType : toppings)
        rightPiece.addTopping(toppingType);
}

void cutRollcake(int toppingType) {
    leftPiece.addTopping(toppingType);
    rightPiece.removeTopping(toppingType);
}

bool isSameNumOfToppingsInAllRollcakePiece() {
    return leftPiece.getNumOfToppingTypes() == rightPiece.getNumOfToppingTypes();
}

int solution(vector<int> topping) {
    
    // rollcake�� ���� ������ ������ �������� ������ �����Ѵ�.
    // ó������ ���� ������ ���� ������ ������ ��ü �������̴�.
    // ������ �������� ���ʺ��� �� ĭ�� �̵��ϸ鼭 �߶󺻴�.    
    // �߶��� �� ������ ������ ������ ���Ѵ�.

    int answer = 0;
    
    makeInitRollcake(topping);

    for (int toppingType : topping) {

        cutRollcake(toppingType);

        if (isSameNumOfToppingsInAllRollcakePiece() == true)
            answer++;

    }

    return answer;
}

void service() {

    vector<int> toppings = { 1, 2, 1, 3, 1, 4, 1, 2 };

    int answer = solution(toppings);
    cout << answer << endl;
}

������ũ_�ڸ���_END
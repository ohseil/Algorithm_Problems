#include "롤케이크_자르기.h"
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

롤케이크_자르기_BEGIN

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
    
    // rollcake을 왼쪽 조각과 오른쪽 조각으로 나눠서 생각한다.
    // 처음에는 왼쪽 조각은 없고 오른쪽 조각은 전체 롤케익이다.
    // 토핑을 기준으로 왼쪽부터 한 칸씩 이동하면서 잘라본다.    
    // 잘랐을 때 토핑의 종류의 개수를 비교한다.

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

롤케이크_자르기_END
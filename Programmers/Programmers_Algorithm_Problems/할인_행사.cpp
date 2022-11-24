#include "할인_행사.h"
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

할인_행사_BEGIN

#define A_PERIOD_OF_MEMBERSHIP 10

#define HashMap unordered_map

HashMap<string, int> needWantProductNumMap;
HashMap<string, int> canBuyDiscountProductNumMap;

void makeNeedWantProductNumMap(vector<string>& wantProducts, vector<int>& wantProductNums) {

    for (int i = 0; i < wantProducts.size(); i++) {

        string wantProduct = wantProducts[i];
        int wantProductNum = wantProductNums[i];
        
        needWantProductNumMap[wantProduct] = wantProductNum;
    }
}

bool canSignUp() {

    for (auto data : needWantProductNumMap) {

        string wantProduct = data.first;
        int needNum = data.second;
        int canBuyProductNum = canBuyDiscountProductNumMap[wantProduct];

        if (canBuyProductNum != needNum)
            return false;
    }

    return true;
}

int findSignUpDates(vector<string>& discountProducts) {

    int canSignUpDateNum = 0;

    for (int day = 0; day < discountProducts.size(); day++) {

        string discountProduct = discountProducts[day];

        if (needWantProductNumMap.count(discountProduct) > 0) {

            canBuyDiscountProductNumMap[discountProduct]++;
        }

        if (day >= A_PERIOD_OF_MEMBERSHIP) {

            string productOutOfRange = discountProducts[day - A_PERIOD_OF_MEMBERSHIP];

            if (needWantProductNumMap.count(productOutOfRange) > 0)
                canBuyDiscountProductNumMap[productOutOfRange]--;
        }

        if (canSignUp() == true)
            canSignUpDateNum++;
    }

    return canSignUpDateNum;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    
    // 원하는 상품들의 개수를 hash map으로 저장해 놓는다.
    // 연속되는 10일 간의 할인 상품들의 개수를 hash map으로 저장해 놓고
    // 앞서 저장해 놓았던 원하는 상품들의 개수와 비교해서 일치하면 회원 가입 가능한 날짜라고 판단한다.       
    // 처음 10일 이후부터는 10일의 범위에 벗어난 이전 상품 데이터를 갱신해 준다.

    int answer = 0;
    
    makeNeedWantProductNumMap(want, number);
    answer = findSignUpDates(discount);

    return answer;
}

void service() {

    vector<string> wants = { "banana", "apple", "rice", "pork", "pot" };
    vector<int> numbers = { 3,2,2,2,1 };
    vector<string> discounts = { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" };

    int answer = solution(wants, numbers, discounts);
    cout << answer << endl;
}

할인_행사_END
#include "����_���.h"
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

����_���_BEGIN

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
    
    // ���ϴ� ��ǰ���� ������ hash map���� ������ ���´�.
    // ���ӵǴ� 10�� ���� ���� ��ǰ���� ������ hash map���� ������ ����
    // �ռ� ������ ���Ҵ� ���ϴ� ��ǰ���� ������ ���ؼ� ��ġ�ϸ� ȸ�� ���� ������ ��¥��� �Ǵ��Ѵ�.       
    // ó�� 10�� ���ĺ��ʹ� 10���� ������ ��� ���� ��ǰ �����͸� ������ �ش�.

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

����_���_END
#include "H-Index.h"
#include <iostream>
#include <vector>

using namespace std;

H_Index_BEGIN

int validation(vector<int>& v, int num) {
    int count = 0;
    for (int data : v)
        if (data >= num)
            count++;
    return count;
}

int solution(vector<int> citations) {
    
    // 이분 탐색 사용

    int answer = 0;
    
    int start = 0, end = 10000, mid;

    while (start <= end) {

        mid = (start + end) / 2;

        int count = validation(citations, mid);

        if (count >= mid) {

            if (answer < mid)
                answer = mid;

            start = mid + 1;
        }
        else if (count < mid) {
            end = mid - 1;
        }
    }

    return answer;
}

void service() {

    vector<int> c = { 1,4 };
    cout << solution(c) << endl;

}

H_Index_END
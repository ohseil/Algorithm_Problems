#include "구명보트.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

구명보트_BEGIN

int solution(vector<int> people, int limit) {

    // 가장 큰 무게를 가진 사람 A를 태운 경우를 생각해 봤을 때,
    // 가장 작은 무게를 가진 사람 B를 같이 태울 수 없다면
    // A는 무조건 혼자 타야한다.
    // B를 같이 태울 수 있다면 A는 B와 같이 탈 수 있다.
    
    // people 배열을 정렬 후, 처음과 마지막에 2개의 포인터 start, end를 둔다.
    // 위의 알고리즘대로 계산하면서 양 끝에서 포인터를 옮긴다.
    // 혼자 타야한다면 end--
    // 두명이 탈 수 있다면 start++, end--

    int answer = 0;

    sort(people.begin(), people.end());

    int start = 0, end = people.size() - 1;

    while (start <= end) {

        if (people[start] + people[end] <= limit) {
            start++;
            end--;
        }
        else {
            end--;
        }

        answer++;
    }

    return answer;
}

void service() {

    vector<int> p = { 70, 50, 80, 50 };
    int limit = 100;
    cout << solution(p, limit) << endl;
}

구명보트_END
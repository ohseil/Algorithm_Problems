#include "금과_은_운반하기.h"
#include <iostream>
#include <vector>

using namespace std;

금과_은_운반하기_BEGIN

bool canCarry(int a, int b, vector<int>& g, vector<int>& s, vector<int>& w, vector<int>& t, long long time) {

    int amount_g = 0;
    int amount_s = 0;
    int amount_all = 0;

    for (int i = 0; i < g.size(); i++) {

        long long one_way_time = (long long)t[i];
        long long two_way_time = one_way_time * 2;

        long long count = (time < one_way_time) ? (0) : (1 + (time - one_way_time) / two_way_time);

        amount_g += min((long long)g[i], w[i] * count);
        amount_s += min((long long)s[i], w[i] * count);
        amount_all += min((long long)g[i] + s[i], w[i] * count);
    }

    return amount_g >= a && amount_s >= b && amount_all >= (a + b);
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    
    // 이분 탐색 사용.
    // 시간 t가 주어졌을 때, 필요한 금과 은의 양만큼 옮길 수 있는지 확인.
    
    // 금만 옮겼을 때 필요한 금의 양을 채울 수 있고
    // 은만 옮겼을 때 필요한 은의 양을 채울 수 있고
    // 금과 은 상관 없이 옮겼을 때 필요한 금과 음의 총합의 양만큼 채울 수 있다면
    // 시간 t동안 필요한 자원을 모두 채울 수 있음을 의미한다.

    long long answer = 10e14 * 4;
    
    long long start = 1, end = 10e14 * 4, mid;

    while (start <= end) {

        mid = (start + end) / 2;

        if (canCarry(a, b, g, s, w, t, mid) == true) {

            if (mid < answer)
                answer = mid;

            end = mid - 1;
        }
        else {
            start = mid + 1;
        }

    }

    return answer;
}

void service() {

    int a = 90;
    int b = 500;
    vector<int> g = { 70,70,0 };
    vector<int> s = { 0,0,500 };
    vector<int> w = { 100,100,2 };
    vector<int> t = { 4,8,1 };

    cout << solution(a, b, g, s, w, t) << endl;
}

금과_은_운반하기_END
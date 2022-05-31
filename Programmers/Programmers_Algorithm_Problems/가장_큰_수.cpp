#include "가장_큰_수.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(string lhs, string rhs) {
    return stoi(lhs + rhs) > stoi(rhs + lhs);
}

string solution(vector<int> numbers) {

    string answer = "";

    vector<string> num_v;

    for (int num : numbers)
        num_v.push_back(to_string(num));

    sort(num_v.begin(), num_v.end(), cmp);

    // 0으로만 이루어져 있다면 정렬 후에 첫번 째 원소가 무조건 0이다.
    if (num_v[0] == "0")
        return "0";

    for (string num : num_v)
        answer += num;

    return answer;
}

void 가장_큰_수::service() {

    vector<int> v = { 3, 30, 34, 5, 9 };
    cout << solution(v) << endl;
}
#include "����_ū_��.h"
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

    // 0���θ� �̷���� �ִٸ� ���� �Ŀ� ù�� ° ���Ұ� ������ 0�̴�.
    if (num_v[0] == "0")
        return "0";

    for (string num : num_v)
        answer += num;

    return answer;
}

void ����_ū_��::service() {

    vector<int> v = { 3, 30, 34, 5, 9 };
    cout << solution(v) << endl;
}
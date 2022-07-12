#include "����_��ȯ_�ݺ��ϱ�.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

����_��ȯ_�ݺ��ϱ�_BEGIN

string getBinary(int len) {

    long long binary = 0;
    long long ten = 1;

    while (len != 0) {
        binary += (len % 2) * ten;
        len /= 2;
        ten *= 10;
    }

    return to_string(binary);
}

int binaryChange(string& num) {

    string changed = "";

    for (char ch : num)
        if (ch == '1')
            changed += ch;

    int zero_count = num.size() - changed.size();
    num = getBinary(changed.size());

    return zero_count;
}

vector<int> solution(string s) {

    // ������ �˰����� ����.

    vector<int> answer(2, 0);

    while (s != "1") {
        answer[1] += binaryChange(s);
        answer[0]++;
    }

    return answer;
}

void service() {

    string s = "110010101001";
    vector<int> ans = solution(s);

    cout << ans[0] << " " << ans[1] << endl;
}

����_��ȯ_�ݺ��ϱ�_END
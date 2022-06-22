#include "ū_��_�����.h"
#include <iostream>
#include <string>

using namespace std;

ū_��_�����_BEGIN

string solution(string number, int k) {
    
    // �� ���ڸ����� Ž���� �����Ѵ�.
    // �� ���ڸ��� �������� k���� �� �� ���� ū ���� Ȯ���ϰ�,
    // ū ���� �������� �� �ڸ� ������ ��� �����Ѵ�.
    // ������ �� ��ŭ k���� ����.
    // �� ū ���� ���� index���� �ٽ� �� ������ �����Ѵ�.

    string answer = "";
    
    int len = number.length();
    int idx = 0;

    while (idx < len && (len - idx) > k && k > 0) {

        int big = -1;
        int b_idx = -1;

        for (int i = idx; i <= idx + k; i++) {
            
            int num = number[i] - 48;

            if (num > big) {
                big = num;
                b_idx = i;
            }
        }

        answer += to_string(big);
        k -= (b_idx - idx);
        idx = b_idx + 1;

    }

    if (k == 0 && idx < len)
        answer += number.substr(idx);

    return answer;
}

void service() {

    string str = "4177252841";
    int k = 4;
    cout << solution(str, k) << endl;

}

ū_��_�����_END
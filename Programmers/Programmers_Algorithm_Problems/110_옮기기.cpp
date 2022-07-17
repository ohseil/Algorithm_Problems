#include "110_�ű��.h"
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

_110_�ű��_BEGIN_

vector<string> solution(vector<string> s) {
    
    // "110"�� �̾Ƽ� � ���� �������� ��,
    // ���� "110"�� ��������� ���� ���� �� �̾����� ���ڿ��� ��� ���̴�.
    // ���� "110"�� ���� �� �������� ���� �ٸ� "110"�� ������� �� ����.
    // �׷��� �����ϱ� ���� "110"�� ��� ã�Ƽ� ������ ����.
    
    // ��� "110"�� ������ �� �����ִ� ���ڿ��� Ȯ���ؼ�
    // ��� "110"�� �����ؾ� �ϴ��� ã�ƺ���,
    // ������ ���ں��� ���ʴ�� ���ڸ� Ȯ������ �� ó�� ������ "0" ���Ŀ�
    // "110"�� ���� ������ŭ �����ϸ� �ȴ�.
    
    // �߰� �κ��� Ȯ���� �ʿ䰡 ���� ������ "110"�� ��� ������,
    // �߰��� "111~"�� ���ڿ��� ����. '1'�� �̾��� ���ڿ��� ������ �������� �ְ� �ȴ�.
    // �߰��� "111~'�� ���ڿ��� �ִٴ� ���� ���� '0'�� �ٴ´ٴ� ���̶� �̰͵� "110"�� �Ǳ� �����̴�.

    vector<string> answer;
    
    for (string str : s) {
     
        int count = 0;

        deque<char> dq;

        for (int i = 0; i < str.length(); i++) {

            if (dq.size() < 2)
                dq.push_back(str[i]);
            else {

                char ch2 = dq.back();
                dq.pop_back();
                char ch1 = dq.back();
                dq.pop_back();

                if (ch1 == '1' && ch2 == '1' && str[i] == '0') {
                    count++;
                }
                else {
                    dq.push_back(ch1);
                    dq.push_back(ch2);
                    dq.push_back(str[i]);
                }
                    
            }
        }

        string ans = "";

        if (dq.empty() == true) {

            while (count--)
                ans += "110";
        }
        else {

            str = "";

            while (dq.empty() == false) {
                str += dq.front();
                dq.pop_front();
            }

            int input_idx = 0;

            for (int i = str.length() - 1; i >= 0; i--) {
                if (str[i] == '0') {
                    input_idx = i + 1;
                    break;
                }
            }

            ans = str.substr(0, input_idx);

            while (count--)
                ans += "110";

            ans += str.substr(input_idx);
        }

        answer.push_back(ans);
    }  

    return answer;
}

void service() {

    vector<string> v = { "1110","100111100","0111111010" };
    vector<string> ans = solution(v);

    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

_110_�ű��_END_
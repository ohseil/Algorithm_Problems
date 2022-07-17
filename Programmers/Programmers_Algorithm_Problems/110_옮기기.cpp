#include "110_옮기기.h"
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

_110_옮기기_BEGIN_

vector<string> solution(vector<string> s) {
    
    // "110"을 뽑아서 어떤 곳에 삽입했을 때,
    // 새로 "110"이 만들어지는 곳은 뽑은 후 이어지는 문자열의 경우 뿐이다.
    // 뽑은 "110"이 삽입 된 곳에서는 새로 다른 "110"이 만들어질 수 없다.
    // 그래서 삽입하기 전에 "110"을 계속 찾아서 개수를 센다.
    
    // 모든 "110"이 뽑혔을 때 남아있는 문자열을 확인해서
    // 어디에 "110"을 삽입해야 하는지 찾아보면,
    // 마지막 문자부터 차례대로 문자를 확인했을 때 처음 나오는 "0" 이후에
    // "110"을 뽑은 개수만큼 삽입하면 된다.
    
    // 중간 부분을 확인할 필요가 없는 이유는 "110"을 계속 뽑으면,
    // 중간에 "111~"의 문자열이 없다. '1'이 이어진 문자열은 무조건 마지막에 있게 된다.
    // 중간에 "111~'의 문자열이 있다는 것은 끝에 '0'이 붙는다는 것이라 이것도 "110"이 되기 때문이다.

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

_110_옮기기_END_
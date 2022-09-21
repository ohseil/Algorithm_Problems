#include "압축.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

압축_BEGIN

void setDictionary(map<string, int>& dictionary, int& indexSequence) {

    for (char ch = 'A'; ch <= 'Z'; ch++) {
        string str = "";
        str += ch;
        dictionary[str] = indexSequence;
        indexSequence++;
    }
}

void searchString(map<string, int>& dictionary, string msg, int& indexSequence, vector<int>& answer) {

    for (int i = 0; i < msg.length(); i++) {

        string str = "";

        for (int j = i; j < msg.length(); j++) {
            
            string newStr = str + msg[j];

            if (dictionary.find(newStr) == dictionary.end()) {
                answer.push_back(dictionary[str]);
                dictionary[newStr] = indexSequence++;
                i = j - 1;
                break;
            }

            if (j == msg.length() - 1) {
                answer.push_back(dictionary[newStr]);
                return;
            }

            str = newStr;
        }
    }
}

vector<int> solution(string msg) {
    
    // 단순 구현 문제

    vector<int> answer;
    
    map<string, int> dictionary;

    int indexSequence = 1;

    setDictionary(dictionary, indexSequence);
    searchString(dictionary, msg, indexSequence, answer);

    return answer;
}

void service() {

    string msg = "KAKAO";
    
    vector<int> ans = solution(msg);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

압축_END
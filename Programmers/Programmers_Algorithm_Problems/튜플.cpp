#include "튜플.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

튜플_BEGIN

string removeBraces(string& s) {
    string removedStr = "";
    for (char ch : s)
        if (ch != '{' && ch != '}')
            removedStr += ch;
    return removedStr;
}

vector<string> split(string str, char delimiter) {

    istringstream iss(str);
    string buffer;

    vector<string> result;

    while (getline(iss, buffer, delimiter)) {
        result.push_back(buffer);
    }

    return result;
}

bool cmp(pair<int, int> lhs, pair<int, int> rhs) {
    if (lhs.second > rhs.second)
        return true;
    return false;
}

vector<int> solution(string s) {
    
    // 모든 숫자의 개수를 세서 개수가 많은 순서대로 정렬한다.

    vector<int> answer;
    
    map<string, int> numCounts;
    vector<pair<int, int>> sortedV;

    string removedStr = removeBraces(s);

    vector<string> nums = split(removedStr, ',');

    for (string num : nums)
        numCounts[num]++;

    for (auto numCount : numCounts)
        sortedV.emplace_back(stoi(numCount.first), numCount.second);

    sort(sortedV.begin(), sortedV.end(), cmp);

    for (auto inform : sortedV)
        answer.push_back(inform.first);

    return answer;
}

void service() {

    string str = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
    
    vector<int> ans = solution(str);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

튜플_END
#include "불량_사용자.h"
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <unordered_set>

using namespace std;

불량_사용자_BEGIN

#define hashSet unordered_set

void makeBannedPattern(vector<string>& bannedIds, vector<regex>& bannedPatterns) {

    for (string bannedId : bannedIds) {

        string patternStr = "";

        for (char ch : bannedId) {
            if (ch == '*') {
                patternStr += "[^*]";
            }
            else {
                patternStr += ch;
            }
        }

        bannedPatterns.push_back(regex(patternStr));
    }
}

bool isBannedId(string& id, regex& bannedPattern) {
    return regex_match(id, bannedPattern);
}

void matchErrorUserList(vector<string>& userIds, vector<regex>& bannedPatterns, vector<bool> validations, int depth, hashSet<vector<bool>>& listValidations, int& answer) {

    if (depth == bannedPatterns.size()) {
        if (listValidations.count(validations) == 0) {
            listValidations.insert(validations);
            answer++;
        }
        return;
    }

    regex bannedPattern = bannedPatterns[depth];

    for (int i = 0; i < userIds.size(); i++) {
        
        if (validations[i] == true)
            continue;

        string userId = userIds[i];

        if (isBannedId(userId, bannedPattern) == true) {
            vector<bool> nextValidations = validations;
            nextValidations[i] = true;
            matchErrorUserList(userIds, bannedPatterns, nextValidations, depth + 1, listValidations, answer);
        }
    }

}

int solution(vector<string> user_id, vector<string> banned_id) {
    
    // 정규식을 이용한다.
    // 불량 사용자 아이디 리스트를 정규식 패턴 리스트로 만들어서 사용한다.
    // 모든 제재 아이디 리스트를 탐색한다.
    // 탐색 과정에서 이전에 탐색했던 리스트를 hash set에 저장해 두었다가 중복되면 포함시키지 않는다.

    int answer = 0;
    
    vector<regex> bannedPatterns;
    hashSet<vector<bool>> listValidations;

    makeBannedPattern(banned_id, bannedPatterns);
    matchErrorUserList(user_id, bannedPatterns, vector<bool>(user_id.size(), false), 0, listValidations, answer);

    return answer;
}

void service() {

    vector<string> userIds = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
    vector<string> bannedIds = { "fr*d*", "abc1**" };

    cout << solution(userIds, bannedIds) << endl;
}

불량_사용자_END
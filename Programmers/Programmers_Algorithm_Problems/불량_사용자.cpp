#include "�ҷ�_�����.h"
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <unordered_set>

using namespace std;

�ҷ�_�����_BEGIN

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
    
    // ���Խ��� �̿��Ѵ�.
    // �ҷ� ����� ���̵� ����Ʈ�� ���Խ� ���� ����Ʈ�� ���� ����Ѵ�.
    // ��� ���� ���̵� ����Ʈ�� Ž���Ѵ�.
    // Ž�� �������� ������ Ž���ߴ� ����Ʈ�� hash set�� ������ �ξ��ٰ� �ߺ��Ǹ� ���Խ�Ű�� �ʴ´�.

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

�ҷ�_�����_END
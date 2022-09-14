#include "¿ÀÇÂÃ¤ÆÃ¹æ.h"
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

¿ÀÇÂÃ¤ÆÃ¹æ_BEGIN

void extractFromRecord(string& record, unordered_map<string, string>& nicknameByIds, vector<pair<string, string>>& enterLeaveRecords) {

    string work, id, nickname;

    work = record.substr(0, record.find(" "));
    record = record.substr(record.find(" ") + 1);

    if (work == "Enter") {
        id = record.substr(0, record.find(" "));
        nickname = record.substr(record.find(" ") + 1);
        nicknameByIds[id] = nickname;
        enterLeaveRecords.emplace_back(work, id);
    }
    else if (work == "Leave") {
        id = record.substr(0, record.find(" "));
        nickname = record.substr(record.find(" ") + 1);
        enterLeaveRecords.emplace_back(work, id);
    }
    else if (work == "Change") {
        id = record.substr(0, record.find(" "));
        nickname = record.substr(record.find(" ") + 1);
        nicknameByIds[id] = nickname;
    }

}

vector<string> solution(vector<string> record) {
    
    vector<string> answer;
    
    unordered_map<string, string> nicknameByIds;
    vector<pair<string, string>> enterLeaveRecords;

    for (string r : record)
        extractFromRecord(r, nicknameByIds, enterLeaveRecords);

    for (pair<string, string> elRecord : enterLeaveRecords) {

        string work = elRecord.first;
        string id = elRecord.second;
        string nickname = nicknameByIds[id];

        if (work == "Enter")
            answer.push_back(nickname + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
        else
            answer.push_back(nickname + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
    }

    return answer;
}

void service() {

    vector<string> records = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };

    vector<string> ans = solution(records);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

¿ÀÇÂÃ¤ÆÃ¹æ_END
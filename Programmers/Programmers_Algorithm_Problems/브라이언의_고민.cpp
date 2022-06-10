#include "브라이언의_고민.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

브라이언의_고민_BEGIN

#define INVALID "invalid"

string solution(string sentence) {
    
    string answer = "";
    
    // 공백이 있다면 invalid.
    if (0 <= sentence.find(" ") && sentence.find(" ") < sentence.length())
        return INVALID;

    map<char, vector<int>> pattern_map;
    vector<vector<char>> pattern_v(sentence.size(), vector<char>({ '?', '?' })); // 0번이 패턴1, 1번이 패턴 2.

    for (int i = 0; i < sentence.length(); i++) {

        if (sentence[i] == tolower(sentence[i]))
            pattern_map[sentence[i]].push_back(i);
    }

    // 패턴 1 확인
    for (auto pattern : pattern_map) {

        if (pattern.second.size() == 2)
            continue;

        char ch = pattern.first;
        vector<int> index_v = pattern.second;

        // 패턴 1의 소문자가 문자열 양 끝에 있다면 invalid.
        if (index_v[0] == 0 || index_v[index_v.size() - 1] == sentence.length() - 1)
            return INVALID;

        // 소문자 사이에 다른 문자가 2개 이상인 경우.
        for (int i = 0; i < index_v.size() - 1; i++)
            if (index_v[i + 1] - index_v[i] > 2)
                return INVALID;

        // 소문자 사이에 대문자가 아닌 경우
        if (sentence[index_v[0] - 1] == tolower(sentence[index_v[0] - 1]))
            return INVALID;

        for (int i = 0; i < index_v.size(); i++)
            if (sentence[index_v[i] + 1] == tolower(sentence[index_v[i] + 1]))
                return INVALID;

        // 이미 다른 패턴1이 적용된 단어인 경우
        if (pattern_v[index_v[0] - 1][0] != '?' || pattern_v[index_v[index_v.size() - 1] + 1][0] != '?')
            return INVALID;

        // 각 문자에 적용된 패턴 기록.
        pattern_v[index_v[0] - 1][0] = ch;
        for (int i = 0; i < index_v.size(); i++) {
            pattern_v[index_v[i] + 1][0] = ch;
        }
    }

    // 패턴 2 확인
    for (auto pattern : pattern_map) {

        if (pattern.second.size() != 2)
            continue;

        char ch = pattern.first;
        vector<int> index_v = pattern.second;
        int s = index_v[0], e = index_v[1];

        // 앞 소문자 바로 뒤에 대문자가 아니거나
        // 뒷 소문자 바로 앞에 대문자가 아닌 경우
        if (sentence[s + 1] == tolower(sentence[s + 1]))
            return INVALID;
        if (sentence[e - 1] == tolower(sentence[e - 1]))
            return INVALID;

        // 이미 다른 패턴2가 적용되었는지 확인
        bool isAnother = false;

        for (int i = s + 1; i < e; i++)
            if (pattern_v[i][1] != '?') {
                isAnother = true;
                break;
            }

        if (isAnother == true) {
            if (e - s == 6) {
                // aAbAbAa 이 패턴에서 안의 패턴 후 바깥 패턴을 확인하는 경우
                // 안의 패턴2를 패턴1로 바꿀 수 있다.
                // 이 패턴이 아니라면 바꿀 수 없기 때문에 invalid.
                if (sentence[s + 2] != tolower(sentence[s + 2]))
                    return INVALID;
                if (sentence[s + 2] != sentence[s + 4])
                    return INVALID;
                if (sentence[s + 3] == tolower(sentence[s + 3]))
                    return INVALID;

                for (int i = s + 1; i < e; i++)
                    if (pattern_v[i][0] != '?')
                        return INVALID;
                for (int i = s + 1; i < e; i++)
                    pattern_v[i][0] = sentence[s + 2];
            }
            else if (e - s == 2) {
                // aAbAbAa 패턴에서 바깥 패턴 후 안의 패턴의 경우
                // 패턴 1로 변경해야 한다.
                if (pattern_v[s - 1][0] != '?' ||
                    pattern_v[s + 1][0] != '?' ||
                    pattern_v[e + 1][0] != '?')
                    return INVALID;

                pattern_v[s - 1][0] = ch;
                pattern_v[s + 1][0] = ch;
                pattern_v[e + 1][0] = ch;
            }
            else
                return INVALID;
        }
        else {
            for (int i = s + 1; i < e; i++)
                pattern_v[i][1] = ch;
        }

    }

    // 단어 복원
    vector<char> p;

    for (int i = 0; i < sentence.length(); i++) {
        
        char ch = sentence[i];

        if (ch == tolower(ch))
            continue;

        if (pattern_v[i] != p) {
            
            if (answer.length() != 0)
                answer += " ";
            p = pattern_v[i];
        }

        answer += ch;
    }

    return answer;
}

void service() {

    string str = "HaEaLaLaObWORLDb";
    cout << solution(str) << endl;

}

브라이언의_고민_END
#include "����̾���_���.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

����̾���_���_BEGIN

#define INVALID "invalid"

string solution(string sentence) {
    
    string answer = "";
    
    // ������ �ִٸ� invalid.
    if (0 <= sentence.find(" ") && sentence.find(" ") < sentence.length())
        return INVALID;

    map<char, vector<int>> pattern_map;
    vector<vector<char>> pattern_v(sentence.size(), vector<char>({ '?', '?' })); // 0���� ����1, 1���� ���� 2.

    for (int i = 0; i < sentence.length(); i++) {

        if (sentence[i] == tolower(sentence[i]))
            pattern_map[sentence[i]].push_back(i);
    }

    // ���� 1 Ȯ��
    for (auto pattern : pattern_map) {

        if (pattern.second.size() == 2)
            continue;

        char ch = pattern.first;
        vector<int> index_v = pattern.second;

        // ���� 1�� �ҹ��ڰ� ���ڿ� �� ���� �ִٸ� invalid.
        if (index_v[0] == 0 || index_v[index_v.size() - 1] == sentence.length() - 1)
            return INVALID;

        // �ҹ��� ���̿� �ٸ� ���ڰ� 2�� �̻��� ���.
        for (int i = 0; i < index_v.size() - 1; i++)
            if (index_v[i + 1] - index_v[i] > 2)
                return INVALID;

        // �ҹ��� ���̿� �빮�ڰ� �ƴ� ���
        if (sentence[index_v[0] - 1] == tolower(sentence[index_v[0] - 1]))
            return INVALID;

        for (int i = 0; i < index_v.size(); i++)
            if (sentence[index_v[i] + 1] == tolower(sentence[index_v[i] + 1]))
                return INVALID;

        // �̹� �ٸ� ����1�� ����� �ܾ��� ���
        if (pattern_v[index_v[0] - 1][0] != '?' || pattern_v[index_v[index_v.size() - 1] + 1][0] != '?')
            return INVALID;

        // �� ���ڿ� ����� ���� ���.
        pattern_v[index_v[0] - 1][0] = ch;
        for (int i = 0; i < index_v.size(); i++) {
            pattern_v[index_v[i] + 1][0] = ch;
        }
    }

    // ���� 2 Ȯ��
    for (auto pattern : pattern_map) {

        if (pattern.second.size() != 2)
            continue;

        char ch = pattern.first;
        vector<int> index_v = pattern.second;
        int s = index_v[0], e = index_v[1];

        // �� �ҹ��� �ٷ� �ڿ� �빮�ڰ� �ƴϰų�
        // �� �ҹ��� �ٷ� �տ� �빮�ڰ� �ƴ� ���
        if (sentence[s + 1] == tolower(sentence[s + 1]))
            return INVALID;
        if (sentence[e - 1] == tolower(sentence[e - 1]))
            return INVALID;

        // �̹� �ٸ� ����2�� ����Ǿ����� Ȯ��
        bool isAnother = false;

        for (int i = s + 1; i < e; i++)
            if (pattern_v[i][1] != '?') {
                isAnother = true;
                break;
            }

        if (isAnother == true) {
            if (e - s == 6) {
                // aAbAbAa �� ���Ͽ��� ���� ���� �� �ٱ� ������ Ȯ���ϴ� ���
                // ���� ����2�� ����1�� �ٲ� �� �ִ�.
                // �� ������ �ƴ϶�� �ٲ� �� ���� ������ invalid.
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
                // aAbAbAa ���Ͽ��� �ٱ� ���� �� ���� ������ ���
                // ���� 1�� �����ؾ� �Ѵ�.
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

    // �ܾ� ����
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

����̾���_���_END
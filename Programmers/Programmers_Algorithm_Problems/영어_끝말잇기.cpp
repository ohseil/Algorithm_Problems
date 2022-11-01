#include "����_�����ձ�.h"
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

����_�����ձ�_BEGIN

#define HashSet unordered_set

vector<int> turns;
HashSet<string> usedWords;

void init(int n) {
    turns.assign(n + 1, 0);
}

bool satisfyConditions(string& word, string& lastWord) {
    if (word.length() < 2) return false;
    if (word[0] != lastWord[lastWord.length() - 1]) return false;
    if (usedWords.count(word) > 0) return false;
    return true;
}

vector<int> solution(int n, vector<string> words) {
    
    // �ܾ ������ �� Ʋ���� ����
    // 1. �ܾ��� ���̰� 2 �̸��� ���
    // 2. 1�� ���������� ������ �ܾ��� ������ ���ĺ��� �ܾ��� ù ��° ���ĺ��� ��ġ���� �ʴ� ���
    // 3. 1�� 2�� ���������� �̹� ���� �ܾ��� ���

    // �� ���ǵ��� �˻��ϱ� ����,
    // hash set�� ������ �ܾ ������ string ���� lastWord�� ����Ѵ�.
    // hash set���� ���ߴ� �ܾ���� ����Ǿ� �ְ�,
    // lastWord���� �������� ���� �ܾ ����Ǿ� �ִ�.

    // �� ���ʿ� ���ϴ� ����� ��ȣ�� �ܾ��� (index % n + 1)�̴�.
    // ����� ��ȣ�� ������ ������ �ֱ� ������ �迭 turns[n]�� ����Ѵ�.
    // ���ʸ��� turns[index%n+1]++�� �Ѵ�.

    vector<int> answer = {0, 0};

    init(n);

    string lastWord = words[0].substr(0, 1);

    for (int i = 0; i < words.size(); i++) {

        int pnum = i % n + 1;
        int pturn = ++turns[pnum];
        string word = words[i];

        if (satisfyConditions(word, lastWord) == false) {
            answer = { pnum, pturn };
            break;
        }

        lastWord = word;
        usedWords.insert(word);
    }

    return answer;
}

void service() {

    int n = 3;
    vector<string> words = { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" };

    vector<int> ans = solution(n, words);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

����_�����ձ�_END
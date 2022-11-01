#include "영어_끝말잇기.h"
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

영어_끝말잇기_BEGIN

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
    
    // 단어를 말했을 때 틀리는 조건
    // 1. 단어의 길이가 2 미만인 경우
    // 2. 1을 만족하지만 마지막 단어의 마지막 알파벳과 단어의 첫 번째 알파벳이 일치하지 않는 경우
    // 3. 1과 2를 만족하지만 이미 말한 단어인 경우

    // 위 조건들을 검사하기 위해,
    // hash set과 마지막 단어를 저장할 string 변수 lastWord를 사용한다.
    // hash set에는 말했던 단어들이 저장되어 있고,
    // lastWord에는 마지막에 말한 단어가 저장되어 있다.

    // 각 차례에 말하는 사람의 번호는 단어의 (index % n + 1)이다.
    // 사람의 번호는 범위가 정해져 있기 때문에 배열 turns[n]을 사용한다.
    // 차례마다 turns[index%n+1]++을 한다.

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

영어_끝말잇기_END
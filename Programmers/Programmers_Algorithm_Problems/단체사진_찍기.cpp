#include "단체사진_찍기.h"
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

단체사진_찍기_BEGIN

#define HashMap unordered_map

#define EQUAL '='
#define UNDER '<'
#define OVER '>'

bool canLineUp(string people, vector<string> conditions) {

    HashMap<char, int> personPoss;

    for (int i = 0; i < people.length(); i++) {
        char person = people[i];
        personPoss[person] = i;
    }

    for (string condition : conditions) {
        
        char p1 = condition[0];
        char p2 = condition[2];
        char sign = condition[3];
        int distCond = condition[4] - 48;

        int p1pos = personPoss[p1];
        int p2pos = personPoss[p2];
        int dist = abs(p1pos - p2pos) - 1;

        if (sign == EQUAL) {
            if (dist != distCond)
                return false;
        }
        else if (sign == UNDER) {
            if (dist >= distCond)
                return false;
        }
        else if (sign == OVER) {
            if (dist <= distCond)
                return false;
        }
    }

    return true;
}

void permutation(string people, int& answer, int depth, vector<string>& data) {

    if (depth == people.length()) {
        if (canLineUp(people, data) == true)
            answer++;
        return;
    }

    for (int i = depth; i < people.length(); i++) {
        swap(people[i], people[depth]);
        permutation(people, answer, depth + 1, data);
        swap(people[i], people[depth]);
    }
}

int solution(int n, vector<string> data) {
    
    // 모든 줄 세우기 경우를 탐색해서 각 경우마다 모든 조건을 검사한다.

    int answer = 0;
    
    string people = "ACFJMNRT";
    permutation(people, answer, 0, data);

    return answer;
}

void service() {

    int n = 2;
    vector<string> data = { "N~F=0", "R~T>2" };

    cout << solution(n, data) << endl;
}

단체사진_찍기_END
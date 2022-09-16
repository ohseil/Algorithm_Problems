#include "후보키.h"
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

후보키_BEGIN

void makeCombination(int& count, vector<string>& columns, vector<int> combination, int depth, queue<vector<int>>& combinationQ) {

    if (combination.size() == count) {
        combinationQ.push(combination);
        return;
    }

    for (int i = depth; i <= columns.size() - (count - combination.size()); i++) {
        vector<int> next = combination;
        next.push_back(i);
        makeCombination(count, columns, next, i + 1, combinationQ);
    }
}

void checkDuplication(queue<vector<int>>& combinationQ, set<vector<int>> totalCombinations) {

    int qsize = combinationQ.size();

    for (int i = 0; i < qsize; i++) {

        vector<int> combination = combinationQ.front();
        combinationQ.pop();

        bool isExist = false;

        for (vector<int> existingComb : totalCombinations) {

            int existCount = 0;

            for (int col : combination) {
                for (int existingCol : existingComb) {
                    if (col == existingCol)
                        existCount++;
                }
            }

            if (existCount == existingComb.size()) {
                isExist = true;
                break;
            }
        }

        if (isExist == false)
            combinationQ.push(combination);
    }
}

bool checkUniqueness(vector<int>& combination, vector<vector<string>> relation) {

    set<string> validations;

    for (vector<string> tuple : relation) {

        string value = "";

        for (int column : combination) {
            value += tuple[column];
        }

        if (validations.count(value) > 0)
            return false;

        validations.insert(value);
    }

    return true;
}

int solution(vector<vector<string>> relation) {
    
    // 모든 후보키 조합을 탐색한다.
    // 1개, 2개, ~~ n개 조합 순으로 탐색한다.

    // 후보키가 되는 조건은 2가지가 있다.
    // 1. 유일성
    // 2. 최소성

    // 탐색하면서 각 조합마다 최소성을 확인하고
    // 만족한다면 유일성을 확인한다.

    // 최소성은 set을 사용해서 기존에 조합했던 후보키를 저장해놓고 
    // 새로 조합한 컬럼조합에 set에 있는 키 조합이 포함되어 있는지 확인한다.

    int answer = 0;
    int columnCount = relation[0].size();

    set<vector<int>> totalCombinations;

    for (int count = 1; count <= columnCount; count++) {

        queue<vector<int>> combinationQ;

        makeCombination(count, relation[0], vector<int>(), 0, combinationQ);
        checkDuplication(combinationQ, totalCombinations);
        
        while (combinationQ.empty() == false) {

            vector<int> combination = combinationQ.front();
            combinationQ.pop();

            if (checkUniqueness(combination, relation) == true)
                totalCombinations.insert(combination);
        }
    }

    answer = totalCombinations.size();

    return answer;
}

void service() {

    vector<vector<string>> relation = { {"100","ryan","music","2"},{"200","apeach","math","2"},
                                        {"300","tube","computer","3"},{"400","con","computer","4"},
                                        {"500","muzi","music","3"},{"600","apeach","music","2"}};

    cout << solution(relation) << endl;
}

후보키_END
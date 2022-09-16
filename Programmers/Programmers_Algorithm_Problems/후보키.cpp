#include "�ĺ�Ű.h"
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

�ĺ�Ű_BEGIN

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
    
    // ��� �ĺ�Ű ������ Ž���Ѵ�.
    // 1��, 2��, ~~ n�� ���� ������ Ž���Ѵ�.

    // �ĺ�Ű�� �Ǵ� ������ 2������ �ִ�.
    // 1. ���ϼ�
    // 2. �ּҼ�

    // Ž���ϸ鼭 �� ���ո��� �ּҼ��� Ȯ���ϰ�
    // �����Ѵٸ� ���ϼ��� Ȯ���Ѵ�.

    // �ּҼ��� set�� ����ؼ� ������ �����ߴ� �ĺ�Ű�� �����س��� 
    // ���� ������ �÷����տ� set�� �ִ� Ű ������ ���ԵǾ� �ִ��� Ȯ���Ѵ�.

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

�ĺ�Ű_END
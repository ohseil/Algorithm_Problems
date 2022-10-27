#include "스킬트리.h"
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

스킬트리_BEGIN

#define HashSet unordered_set

#define NOT_IN_PRECEDING_SKILL_ORDER -1

bool canLearnSkillTree(string& skillTree, string& skills) {

    HashSet<char> learnedSkills;

    for (char skill : skillTree) {

        int skillIdx = skills.find(skill);

        if (skillIdx != NOT_IN_PRECEDING_SKILL_ORDER) {
            for (int i = 0; i < skillIdx; i++) {
                char needSkill = skills[i];
                if (learnedSkills.count(needSkill) == 0)
                    return false;
            }
        }

        learnedSkills.insert(skill);
    }

    return true;
}

int solution(string skill, vector<string> skill_trees) {
    
    // 스킬트리마다 순서대로 스킬을 배울 수 있는지 확인한다.
    // 배울 수 있는 조건은
    // 1. 선행 스킬 순서에 포함되지 않는 경우
    // 2. 배워야할 스킬의 선행 스킬들을 모두 배운 경우

    // 스킬을 배웠다면 hash set을 사용해서 기록하고 다음에 확인할때 사용한다.

    int answer = 0;
    
    for (string skillTree : skill_trees) {
        if (canLearnSkillTree(skillTree, skill) == true)
            answer++;
    }
    
    return answer;
}

void service() {

    string skill = "CBD";
    vector<string> skillTrees = { "BACDE", "CBADF", "AECB", "BDA" };

    cout << solution(skill, skillTrees) << endl;
}

스킬트리_END
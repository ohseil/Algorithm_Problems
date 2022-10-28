#include "스킬트리.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

스킬트리_BEGIN

#define HashMap unordered_map
#define HashSet unordered_set

void setPrecedingSkillMap(string& skill, HashMap<char, char>& precedingSkillMap) {
    for (int i = 1; i < skill.length(); i++)
        precedingSkillMap[skill[i]] = skill[i - 1];
}

bool canLearnSkillTree(string& skillTree, HashMap<char, char>& precedingSkillMap) {

    HashSet<char> learnedSkillSet;

    for (char skill : skillTree) {

        if (precedingSkillMap.count(skill) > 0) {
            char precedingSkill = precedingSkillMap[skill];
            if (learnedSkillSet.find(precedingSkill) == learnedSkillSet.end())
                return false;
        }

        learnedSkillSet.insert(skill);
    }

    return true;
}

int solution(string skill, vector<string> skill_trees) {
    
    // 스킬트리마다 순서대로 스킬을 배울 수 있는지 확인한다.
    // 배울 수 있는 조건은
    // 1. 선행 스킬 순서에 포함되지 않는 경우
    // 2. 배워야할 스킬의 선행 스킬들을 모두 배운 경우
    //    ( 결국, 바로 앞의 선행 스킬을 배웠는지만 확인하면 된다. 바로 앞의 스킬을 배웠다는 것은 이미 다 배웠다는 것이므로. )

    // 선행 스킬 순서 문자열을 순회해서 hash set에 각 스킬마다 선행해야 하는 바로 앞의 스킬 정보를 저장한다.
    // 배워야 할 스킬이 선행 스킬 순서에 포함된다면,
    // 선행 스킬 정보를 확인하고 해당 스킬을 배웠는지 확인한다.
    // 배운 스킬 정보는 별개로 hash set을 사용해서 기록해 나간다.

    int answer = 0;
    
    HashMap<char, char> precedingSkillMap;

    setPrecedingSkillMap(skill, precedingSkillMap);

    for (string skillTree : skill_trees) {
        if (canLearnSkillTree(skillTree, precedingSkillMap) == true)
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
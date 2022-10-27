#include "��ųƮ��.h"
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

��ųƮ��_BEGIN

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
    
    // ��ųƮ������ ������� ��ų�� ��� �� �ִ��� Ȯ���Ѵ�.
    // ��� �� �ִ� ������
    // 1. ���� ��ų ������ ���Ե��� �ʴ� ���
    // 2. ������� ��ų�� ���� ��ų���� ��� ��� ���

    // ��ų�� ����ٸ� hash set�� ����ؼ� ����ϰ� ������ Ȯ���Ҷ� ����Ѵ�.

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

��ųƮ��_END
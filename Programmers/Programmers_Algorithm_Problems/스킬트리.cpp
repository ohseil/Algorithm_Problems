#include "��ųƮ��.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

��ųƮ��_BEGIN

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
    
    // ��ųƮ������ ������� ��ų�� ��� �� �ִ��� Ȯ���Ѵ�.
    // ��� �� �ִ� ������
    // 1. ���� ��ų ������ ���Ե��� �ʴ� ���
    // 2. ������� ��ų�� ���� ��ų���� ��� ��� ���
    //    ( �ᱹ, �ٷ� ���� ���� ��ų�� ��������� Ȯ���ϸ� �ȴ�. �ٷ� ���� ��ų�� ����ٴ� ���� �̹� �� ����ٴ� ���̹Ƿ�. )

    // ���� ��ų ���� ���ڿ��� ��ȸ�ؼ� hash set�� �� ��ų���� �����ؾ� �ϴ� �ٷ� ���� ��ų ������ �����Ѵ�.
    // ����� �� ��ų�� ���� ��ų ������ ���Եȴٸ�,
    // ���� ��ų ������ Ȯ���ϰ� �ش� ��ų�� ������� Ȯ���Ѵ�.
    // ��� ��ų ������ ������ hash set�� ����ؼ� ����� ������.

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

��ųƮ��_END
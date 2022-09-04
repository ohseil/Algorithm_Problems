#include "�޴�_������.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

�޴�_������_BEGIN

void combination(map<int, map<string, int>>& informs, string& order, string newCourse, int needSize, int curSize, int idx) {

    if (curSize == needSize) {
        informs[needSize][newCourse]--;
        return;
    }

    for (int i = idx; i <= (int)order.length() - (needSize - curSize); i++)
        combination(informs, order, newCourse + order[i], needSize, curSize + 1, i + 1);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    
    // �� �ֹ��� ���� �� ��ǰ �޴����� �ʿ��� ��� ������ Ž���ؼ�
    // �� �޴� �ĺ����� ������ map���� �����Ѵ�.
    // �� ��, Ž�� ���� �� �ֹ��� �����ؼ� ���� ���ĺ� ������ ������ �׻� �����ϰ� �Ѵ�.
    // ������ ������ �� �� �޴� ������ ���� �����͸� �����Ѵ�.
    // Ž���ؼ� ������ �������� ���� �� �޴��� �����Ѵ�.

    vector<string> answer;
    
    // <�޴��� ���� �� ��ǰ �޴��� ����, <�� �޴�, �� �޴� ������ �ֹ��� ��� ��>>
    map<int, map<string, int>> informations;

    for (int i = 0; i < orders.size(); i++)
        sort(orders[i].begin(), orders[i].end());

    for (string order : orders) {
        
        for (int size : course) {

            if (order.length() < size)
                break;

            combination(informations, order, "", size, 0, 0);

        }
    }

    for (auto information : informations) {
    
        map<int, vector<string>> m;

        for (auto newCourse : information.second)
            m[newCourse.second].push_back(newCourse.first);

        if ((*m.begin()).first >= -1)
            continue;

        for (auto newCourse : (*m.begin()).second)
            answer.push_back(newCourse);
    }

    sort(answer.begin(), answer.end());

    return answer;
}

void service() {

    vector<string> orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    vector<int> courses = { 2,3,4 };

    vector<string> ans = solution(orders, courses);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;;
}

�޴�_������_END
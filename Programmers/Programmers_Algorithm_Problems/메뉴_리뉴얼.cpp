#include "메뉴_리뉴얼.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

메뉴_리뉴얼_BEGIN

void combination(map<int, map<string, int>>& informs, string& order, string newCourse, int needSize, int curSize, int idx) {

    if (curSize == needSize) {
        informs[needSize][newCourse]--;
        return;
    }

    for (int i = idx; i <= (int)order.length() - (needSize - curSize); i++)
        combination(informs, order, newCourse + order[i], needSize, curSize + 1, i + 1);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    
    // 각 주문에 포함 된 단품 메뉴들의 필요한 모든 조합을 탐색해서
    // 새 메뉴 후보들의 정보를 map으로 저장한다.
    // 이 때, 탐색 전에 각 주문을 정렬해서 같은 알파벳 조합의 순서가 항상 동일하게 한다.
    // 정보를 저장할 때 새 메뉴 선별을 위한 데이터를 포함한다.
    // 탐색해서 저장한 정보들을 토대로 새 메뉴를 선별한다.

    vector<string> answer;
    
    // <메뉴에 포함 된 단품 메뉴의 개수, <새 메뉴, 새 메뉴 조합을 주문한 사람 수>>
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

메뉴_리뉴얼_END
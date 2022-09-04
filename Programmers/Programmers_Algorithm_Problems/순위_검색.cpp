#include "순위_검색.h"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

순위_검색_BEGIN

#define umap unordered_map

int binarySearch(vector<int>& scores, int& score) {

    int start, end, mid, idx;
    start = 0;
    end = scores.size() - 1;
    idx = scores.size();

    while (start <= end) {

        mid = (start + end) / 2;

        if (scores[mid] >= score) {
            if (mid < idx)
                idx = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    return idx;
}

void storeVolunteerInformation(string& inform, umap<string, vector<int>>& volunteerInforms) {

    string language, work, exp, food;
    int score;

    language = inform.substr(0, inform.find(" "));
    inform = inform.substr(inform.find(" ") + 1);
    work = inform.substr(0, inform.find(" "));
    inform = inform.substr(inform.find(" ") + 1);
    exp = inform.substr(0, inform.find(" "));
    inform = inform.substr(inform.find(" ") + 1);
    food = inform.substr(0, inform.find(" "));

    score = stoi(inform.substr(inform.find(" ") + 1));

    string cond[4] = { language, work, exp, food };

    queue<string> q;
    q.push("");

    for (int i = 0; i < 4; i++) {

        int qsize = q.size();

        for (int qi = 0; qi < qsize; qi++) {

            string key = q.front();
            q.pop();

            q.push(key + cond[i]);
            q.push(key + "-");
        }
    }

    while (q.empty() == false) {

        string key = q.front();
        q.pop();

        volunteerInforms[key].push_back(score);
    }
}

void performQuery(string& query, umap<string, vector<int>>& volunteerInforms, vector<int>& answer) {
    
    string language, work, exp, food;
    int score;

    language = query.substr(0, query.find(" "));
    query = query.substr(query.find(" ") + 5);
    work = query.substr(0, query.find(" "));
    query = query.substr(query.find(" ") + 5);
    exp = query.substr(0, query.find(" "));
    query = query.substr(query.find(" ") + 5);
    food = query.substr(0, query.find(" "));

    score = stoi(query.substr(query.find(" ") + 1));

    string key = "" + language + work + exp + food;

    if (volunteerInforms.count(key) == 0) {
        answer.push_back(0);
        return;
    }

    vector<int> scores = volunteerInforms[key];

    int idx = binarySearch(scores, score);
    answer.push_back(scores.size() - idx);
}

vector<int> solution(vector<string> info, vector<string> query) {

    // 크게 2단계로 진행된다.
    // 1. info를 참고해서 정보 저장
    // 2. 쿼리 수행

    // 정보 저장 단계에서는 hash map을 사용한다.
    // 지원서는 총 4개의 항목이 있고 4개 항목 모두 선택되어 있다.
    // 지원서의 4개의 항목 문자열을 합친 문자열을 key로 해서 점수를 key위치의 vector에 추가한다.
    // 이 때,
    // 쿼리를 통해 조합될 수 있는 모든 key 위치의 vector에 추가해주는 것이 핵심이다.
    // 쿼리에서는 각 항목마다 무조건 선택하는 것이 아닌 모든 조건을 고려할수도 있기 때문이다.
    // 쿼리에서 한 항목이 "-"라면 그 항목의 모든 조건을 고려해야 한다.
    // 그래서 각 지원서마다 조합될 수 있는 key의 수는 2x2x2x2 = 16가지다.
    // 이유는 각 항목마다 지원서에서 선택된 조건이거나 모든 선택지를 고려한다는 조건("-") 2가지다.

    // 모든 정보를 저장한 후에 score가 저장된 vector를 모두 정렬해 준다.
    // 이유는 이후에 쿼리를 수행할 때 이분 탐색을 통해 조건에 맞는 위치를 찾으면
    // vector의 size에서 해당 index를 빼주면 조건의 점수인 x이상의 지원자 수를 알 수 있기 때문이다.

    // 마지막으로 쿼리를 수행한다.
    // 각 쿼리마다 4개의 항목 문자열을 합쳐 key를 만든다.
    // key를 통해 지원자의 점수가 담긴 vector에 접근하고 위와 같은 방식으로 계산한다.

    vector<int> answer;

    umap<string, vector<int>> volunteerInforms;

    for (string inform : info)
        storeVolunteerInformation(inform, volunteerInforms);

    for (auto inform : volunteerInforms) {
        string query = inform.first;
        vector<int>& scores = volunteerInforms[query];
        sort(scores.begin(), scores.end());
    }

    for (string q : query)
        performQuery(q, volunteerInforms, answer);

    return answer;
}

void service() {

    vector<string> infos = { "java backend junior pizza 150",
        "python frontend senior chicken 210",
        "python frontend senior chicken 150",
        "cpp backend senior pizza 260",
        "java backend junior chicken 80",
        "python backend senior chicken 50" };

    vector<string> queries = { "java and backend and junior and pizza 100",
        "python and frontend and senior and chicken 200",
        "cpp and - and senior and pizza 250",
        "- and backend and senior and - 150",
        "- and - and - and chicken 100",
        "- and - and - and - 150" };

    vector<int> ans = solution(infos, queries);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

순위_검색_END
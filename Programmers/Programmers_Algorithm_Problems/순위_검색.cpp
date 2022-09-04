#include "����_�˻�.h"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

����_�˻�_BEGIN

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

    // ũ�� 2�ܰ�� ����ȴ�.
    // 1. info�� �����ؼ� ���� ����
    // 2. ���� ����

    // ���� ���� �ܰ迡���� hash map�� ����Ѵ�.
    // �������� �� 4���� �׸��� �ְ� 4�� �׸� ��� ���õǾ� �ִ�.
    // �������� 4���� �׸� ���ڿ��� ��ģ ���ڿ��� key�� �ؼ� ������ key��ġ�� vector�� �߰��Ѵ�.
    // �� ��,
    // ������ ���� ���յ� �� �ִ� ��� key ��ġ�� vector�� �߰����ִ� ���� �ٽ��̴�.
    // ���������� �� �׸񸶴� ������ �����ϴ� ���� �ƴ� ��� ������ ����Ҽ��� �ֱ� �����̴�.
    // �������� �� �׸��� "-"��� �� �׸��� ��� ������ ����ؾ� �Ѵ�.
    // �׷��� �� ���������� ���յ� �� �ִ� key�� ���� 2x2x2x2 = 16������.
    // ������ �� �׸񸶴� ���������� ���õ� �����̰ų� ��� �������� ����Ѵٴ� ����("-") 2������.

    // ��� ������ ������ �Ŀ� score�� ����� vector�� ��� ������ �ش�.
    // ������ ���Ŀ� ������ ������ �� �̺� Ž���� ���� ���ǿ� �´� ��ġ�� ã����
    // vector�� size���� �ش� index�� ���ָ� ������ ������ x�̻��� ������ ���� �� �� �ֱ� �����̴�.

    // ���������� ������ �����Ѵ�.
    // �� �������� 4���� �׸� ���ڿ��� ���� key�� �����.
    // key�� ���� �������� ������ ��� vector�� �����ϰ� ���� ���� ������� ����Ѵ�.

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

����_�˻�_END
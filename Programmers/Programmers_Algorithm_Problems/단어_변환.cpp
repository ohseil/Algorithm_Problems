#include "�ܾ�_��ȯ.h"
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <map>

using namespace std;

�ܾ�_��ȯ_BEGIN

bool canMove(string start, string end) {
    int count = 0;
    for (int i = 0; i < start.length(); i++)
        if (start[i] != end[i])
            count++;
    return count == 1;
}

int solution(string begin, string target, vector<string> words) {
    
    // bfs ���.
    // �� �ܾ ���, �ܾ�� �ٸ� �ܾ�� ������ �� �ִ� ��츦 �������� �����Ѵ�.

    int answer = 0;
    
    map<string, unordered_set<string>> route_m;

    words.push_back(begin);

    for (int i = 0; i < words.size(); i++) {
        for (int j = i + 1; j < words.size(); j++) {

            if (canMove(words[i], words[j]) == true) {
                route_m[words[i]].insert(words[j]);
                route_m[words[j]].insert(words[i]);
            }

        }
    }

    unordered_set<string> visited_s;
    queue<string> q;

    q.push(begin);
    visited_s.insert(begin);

    for (int i = 0; i < words.size(); i++) {

        int qsize = q.size();

        for (int j = 0; j < qsize; j++) {

            string data = q.front();
            q.pop();

            if (data == target) {
                answer = i;
                return answer;
            }

            for (string next : route_m[data]) {

                if (visited_s.count(next) > 0)
                    continue;

                q.push(next);
                visited_s.insert(next);
            }
        }
    }

    return answer;
}

void service() {

    string begin = "hit";
    string target = "cog";
    vector<string> w = { "hot", "dot", "dog", "lot", "log", "cog" };
    cout << solution(begin, target, w) << endl;
}

�ܾ�_��ȯ_END
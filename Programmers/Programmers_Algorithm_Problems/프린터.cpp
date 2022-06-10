#include "������.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

������_BEGIN

int solution(vector<int> priorities, int location) {
    
    int answer = 0;
    
    queue<pair<int, int>> q; // first : page number, second : priority

    for (int i = 0; i < priorities.size(); i++)
        q.push({ i, priorities[i] });

    while (q.empty() == false) {

        pair<int, int> data = q.front();
        q.pop();

        bool isHighPriority = false;

        int qsize = q.size();

        for (int i = 0; i < qsize; i++) {

            pair<int, int> page = q.front();
            q.pop();

            if (page.second > data.second)
                isHighPriority = true;
            
            q.push(page);
        }

        if (isHighPriority == true) {
            q.push(data);
        }
        else {
            // ������ ����Ʈ
            answer++;
            if (data.first == location)
                break;
        }
    }

    return answer;
}

void service() {

    vector<int> p = { 2, 1, 3, 2 };
    int location = 2;

    cout << solution(p, location) << endl;
}

������_END
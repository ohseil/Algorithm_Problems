#include "��ũ_��Ʈ�ѷ�.h"
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

��ũ_��Ʈ�ѷ�_BEGIN

class Job {
public:
    int t_request;
    int t_work;
    Job(int tr, int tw) : t_request(tr), t_work(tw) {}
    Job();
};

class cmp {
public:
    bool operator()(pair<int, Job> lhs, pair<int, Job> rhs) {
        return lhs.first > rhs.first;
    }
};

int solution(vector<vector<int>> jobs) {
    
    int answer = 0;
    
    map<int, vector<Job>> job_map;

    for (auto job : jobs)
        job_map[job[0]].push_back(Job(job[0], job[1]));

    priority_queue<pair<int, Job>, vector<pair<int, Job>>, cmp> wait_q; // first : �۾� �ð�, second : job ����
    queue<pair<int, Job>> job_q; // first : �۾� ���� �ð�, second : job ����

    for (int time = 0; time <= 500000; time++) {

        // ���� �۾��� �ִٸ� ó��
        if (job_q.empty() == false) {
            
            int t_start = job_q.front().first;
            Job working = job_q.front().second;
            if (t_start + working.t_work <= time) {
                answer += (time - working.t_request);
                job_q.pop();
            }
        }

        // ��û �� �۾��� �ִٸ� ��� ť�� ����.
        for (auto job : job_map[time])
            wait_q.push({ job.t_work, job });

        // �������� �۾��� ���� ��� ��� ť�� �ִ� �۾� ����
        if (job_q.empty() == true && wait_q.empty() == false) {
            job_q.push({ time, wait_q.top().second });
            wait_q.pop();
        }
    }

    return answer / jobs.size();
}

void service() {

    cout << solution({ {0,3},{1,9},{2,6} }) << endl;

}

��ũ_��Ʈ�ѷ�_END
#include "디스크_컨트롤러.h"
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

디스크_컨트롤러_BEGIN

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

    priority_queue<pair<int, Job>, vector<pair<int, Job>>, cmp> wait_q; // first : 작업 시간, second : job 정보
    queue<pair<int, Job>> job_q; // first : 작업 시작 시간, second : job 정보

    for (int time = 0; time <= 500000; time++) {

        // 끝난 작업이 있다면 처리
        if (job_q.empty() == false) {
            
            int t_start = job_q.front().first;
            Job working = job_q.front().second;
            if (t_start + working.t_work <= time) {
                answer += (time - working.t_request);
                job_q.pop();
            }
        }

        // 요청 온 작업이 있다면 대기 큐에 삽입.
        for (auto job : job_map[time])
            wait_q.push({ job.t_work, job });

        // 진행중인 작업이 없는 경우 대기 큐에 있는 작업 실행
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

디스크_컨트롤러_END
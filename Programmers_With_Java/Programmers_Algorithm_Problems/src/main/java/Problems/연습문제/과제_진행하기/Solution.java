package Problems.연습문제.과제_진행하기;

/*

    각 과제의 시작 시점을 기준으로 계산을 진행한다.
    현재 과제를 끝낼 수 없다면 미룬다.
    현재 과제를 끝낼 수 있다면, 남은 시간에 미뤄뒀던 과제를 최근 순으로 끝낸다.

 */

import java.util.*;

public class Solution {

    static class Problem implements Comparable<Problem> {

        String name;
        int start;
        int playtime;

        Problem(String name, int start, int playtime) {
            this.name = name;
            this.start = start;
            this.playtime = playtime;
        }

        @Override
        public int compareTo(Problem o) {
            return this.start - o.start;
        }
    }

    final List<Problem> problems = new ArrayList<>();
    final Deque<Problem> problemQueue = new LinkedList<>();

    public void service() {
        final String[][] plans = {{"science", "12:40", "50"}, {"music", "12:20", "40"}, {"history", "14:00", "30"}, {"computer", "12:30", "100"}};

        final String[] answer = solution(plans);
        for (String a : answer) {
            System.out.print(a + " ");
        }
    }

    public String[] solution(final String[][] plans) {
        final String[] answer = new String[plans.length];
        int answerIdx = 0;

        makeList(plans);

        for (int i = 0; i < problems.size() - 1; i++) {
            Problem problem = problems.get(i);
            int nextStartTime = problems.get(i + 1).start;

            if (problem.start + problem.playtime <= nextStartTime) {
                // 시간이 남는다.
                answer[answerIdx++] = problem.name;

                int restTime = nextStartTime - (problem.start + problem.playtime);

                while (!problemQueue.isEmpty()) {
                    Problem stoppedProblem = problemQueue.peekFirst();

                    if (stoppedProblem.playtime <= restTime) {
                        restTime -= stoppedProblem.playtime;
                        answer[answerIdx++] = stoppedProblem.name;
                        problemQueue.pollFirst();
                    } else {
                        stoppedProblem.playtime -= restTime;
                        break;
                    }
                }
            } else {
                // 시간이 모자라서 미룬다.
                problem.playtime = (problem.start + problem.playtime) - nextStartTime;
                problemQueue.addFirst(problem);
            }
        }

        // 마지막 과제와 미뤄뒀던 과제 모두 끝내기
        answer[answerIdx++] = problems.get(problems.size() - 1).name;
        while (!problemQueue.isEmpty()) {
            answer[answerIdx++] = problemQueue.pollFirst().name;
        }
        return answer;
    }

    private void makeList(final String[][] plans) {
        for (String[] plan : plans) {
            problems.add(new Problem(plan[0], timeToMin(plan[1]), Integer.parseInt(plan[2])));
        }
        Collections.sort(problems);
    }

    private int timeToMin(String time) {
        String[] times = time.split(":");
        return Integer.parseInt(times[0]) * 60 + Integer.parseInt(times[1]);
    }
}

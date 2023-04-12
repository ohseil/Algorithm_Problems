package Problems.연습문제.호텔_대실;

import java.util.Map;
import java.util.TreeMap;

/**
 * 전체 구간에서 동시에 대실 되어 있는 방의 최대 개수를 구하는 문제에서 살짝 변형된 문제다.
 * 대실이 끝난 후 10분 동안 청소 시간이므로 사용을 못 한다는 조건이 있다.
 * 이 청소 시간을 대실 시간에 포함시켜서 청소 시간까지 사용 시간으로 생각하고 계산한다.
 */

public class Solution {

    Map<Integer, Integer> timeLine = new TreeMap<>();

    public void service() {
        final String[][] bookTimes = {{"10:20", "12:30"}, {"10:20", "12:30"}, {"10:20", "12:30"}};

        final int answer = solution(bookTimes);
        System.out.println(answer);
    }

    public int solution(final String[][] bookTimes) {
        int answer = 0;

        makeTimeLine(bookTimes);

        answer = findMaxNeedRoomCnt();
        return answer;
    }

    private void makeTimeLine(final String[][] bookTimes) {
        for (String[] bookTime : bookTimes) {
            final int start = timeToMin(bookTime[0]);
            final int end = timeToMin(bookTime[1]) + 10;

            timeLine.put(start, timeLine.getOrDefault(start, 0) + 1);
            timeLine.put(end, timeLine.getOrDefault(end, 0) - 1);
        }
    }

    private int timeToMin(final String time) {
        final String[] times = time.split(":");
        return Integer.parseInt(times[0]) * 60 + Integer.parseInt(times[1]);
    }

    private int findMaxNeedRoomCnt() {
        int maxNeedRoomCnt = 0;
        int needRoomCnt = 0;
        for (int time : timeLine.keySet()) {
            needRoomCnt += timeLine.get(time);

            if (needRoomCnt > maxNeedRoomCnt) {
                maxNeedRoomCnt = needRoomCnt;
            }
        }

        return maxNeedRoomCnt;
    }
}

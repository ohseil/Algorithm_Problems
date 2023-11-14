package Problems._2022_KAKAO_BLIND_RECRUITMENT.주차_요금_계산;

import java.util.Map;
import java.util.TreeMap;

/**
 * 순서가 있는 Map을 사용하여 차번호를 key로 하고 총 이용 시간과 출입 시간을 value로 하는 정보를 관리한다.
 * 모든 record를 차례대로 순회하여 각 차의 총 이용시간을 map에 저장한다.
 *
 * map을 차례대로 순회하여 총 부과해야 할 비용을 계산하면,
 * 순서가 있는 map이기 때문에 낮은 번호의 차량부터 차례대로 구할 수 있다.
 */

public class Solution {

    private final Map<Integer, Data> map = new TreeMap<>();
    private int basicTime;
    private int basicFee;
    private int unitTime;
    private int unitFee;

    public void service() {
        int[] fees = new int[]{180, 5000, 10, 600};
        String[] records = new String[]{
                "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT",
                "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN",
                "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"
        };

        int[] answer = solution(fees, records);
        for (int a : answer) {
            System.out.print(a + " ");
        }
    }

    public int[] solution(int[] fees, String[] records) {
        int[] answer = {};
        int inputIdx = 0;

        basicTime = fees[0];
        basicFee = fees[1];
        unitTime = fees[2];
        unitFee = fees[3];

        for (String record : records) {
            analyzeAndRecord(record);
        }

        answer = new int[map.size()];

        for (final int carNum : map.keySet()) {
            Data data = map.get(carNum);

            if (data.inMin > -1) {
                data.totalTime += (timeToMin("23:59") - data.inMin);
            }
            answer[inputIdx++] = basicFee + findChargeCnt(data.totalTime - basicTime) * unitFee;
        }
        return answer;
    }

    private int timeToMin(String time) {
        return Integer.parseInt(time.substring(0, 2)) * 60 +
                Integer.parseInt(time.substring(3, 5));
    }

    private void analyzeAndRecord(String record) {
        String[] tokens = record.split(" ");

        int min = timeToMin(tokens[0]);
        int carNum = Integer.parseInt(tokens[1]);
        String action = tokens[2];

        if (action.equals("IN")) {
            Data data = map.getOrDefault(carNum, new Data());
            data.inMin = min;
            map.put(carNum, data);
        } else if (action.equals("OUT")) {
            Data data = map.get(carNum);
            data.totalTime += (min - data.inMin);
            data.inMin = -1;
        }
    }

    private int findChargeCnt(int min) {
        if (min <= 0) {
            return 0;
        }
        if (min % unitTime == 0) {
            return min / unitTime;
        }
        return min / unitTime + 1;
    }

    static class Data {
        int totalTime = 0;
        int inMin = -1;
    }
}

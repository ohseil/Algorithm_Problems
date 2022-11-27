package Problems.연습문제.귤_고르기;

import java.util.*;

public class Solution {

    private class Tangerine implements Comparable<Tangerine> {
        int kinds;
        int num;

        public Tangerine(int kinds, int num) {
            this.kinds = kinds;
            this.num = num;
        }

        @Override
        public int compareTo(Tangerine tangerine) {
            return tangerine.num - this.num;
        }
    }

    private Map<Integer, Integer> numOfTangerinesPerKindsMap;
    private List<Tangerine> tangerineList;

    private void init() {
        numOfTangerinesPerKindsMap = new HashMap<>();
        tangerineList = new ArrayList<>();
    }

    private void countNumOfTangerinePerKinds(int[] tangerines) {
        for (int kindsOfTangerine : tangerines) {
            int numOfTangerines = numOfTangerinesPerKindsMap.getOrDefault(kindsOfTangerine, 0);
            numOfTangerinesPerKindsMap.put(kindsOfTangerine, numOfTangerines + 1);
        }
    }

    private void convertMapToList() {
        for (int kindsOfTangerine : numOfTangerinesPerKindsMap.keySet()) {
            int numOfTangerines = numOfTangerinesPerKindsMap.getOrDefault(kindsOfTangerine, 0);
            tangerineList.add(new Tangerine(kindsOfTangerine, numOfTangerines));
        }
    }

    private int getNumOfKindsByPickingTangerinesWithMinKinds(int needNumOfTangerines) {

        int numOfTangerineKinds = 0;

        Collections.sort(tangerineList);

        for (Tangerine tangerine : tangerineList) {

            if (needNumOfTangerines <= 0)
                break;

            int numOfTangerines = numOfTangerinesPerKindsMap.get(tangerine.kinds);

            numOfTangerineKinds++;
            needNumOfTangerines -= numOfTangerines;
        }

        return numOfTangerineKinds;
    }

    public int solution(int k, int[] tangerine) {

        // 가장 적은 종류로 귤을 따기 위해서는,
        // 가장 많은 개수를 가진 종류부터 따면 된다.

        int answer = 0;

        init();
        countNumOfTangerinePerKinds(tangerine);
        convertMapToList();

        answer = getNumOfKindsByPickingTangerinesWithMinKinds(k);

        return answer;
    }

    public void service() {

        int k = 6;
        int[] tangerine = {1, 3, 2, 5, 4, 5, 2, 3};

        int answer = solution(k, tangerine);
        System.out.println(answer);
    }
}

package Problems.연습문제.광물_캐기;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Map;

/**
 * 기본 아이디어는 광물을 5개씩 잘랐을 때, 피로도가 많이 소요되는 순서대로 남아있는 곡괭이중 가장 좋은 곡괭이를 사용하는 것이다.
 * 이 때, 고려해야 할 것은 곡괭이의 초기 개수에 따라 캐지 못하는 광물이 있을 수 있기 때문에
 * 곡괭이의 총 개수를 고려해서 캘 수 있는 광물에 대해서만 계산을 진행한다.
 */

public class Solution {

    private static final Map<String, Integer> WEIGHTS = Map.of("diamond", 25, "iron", 5, "stone", 1);
    private static final String[] PICK_NAMES = {"diamond", "iron", "stone"};

    private static final Map<String, Map<String, Integer>> COSTS = Map.of(
            "diamond", Map.of("diamond", 1, "iron", 1, "stone", 1),
            "iron", Map.of("diamond", 5, "iron", 1, "stone", 1),
            "stone", Map.of("diamond", 25, "iron", 5, "stone", 1)
    );

    final List<Data> weights = new ArrayList<>();

    public void service() {
        final int[] picks = {1,3,2};
        final String[] minerals = {"diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone"};

        final int answer = solution(picks, minerals);
        System.out.println(answer);
    }

    public int solution(int[] picks, final String[] minerals) {
        int answer = 0;

        makeWeights(picks, minerals);
        Collections.sort(weights);

        for (Data data : weights) {
            if (picks[0] == 0 && picks[1] == 0 && picks[2] == 0) {
                break;
            }

            int idx = data.index;
            String pick_name = findPickName(picks);

            for (int i = idx; (i < idx + 5) && (i < minerals.length); i++) {
                answer += COSTS.get(pick_name).get(minerals[i]);
            }
        }
        return answer;
    }

    private void makeWeights(final int[] picks, final String[] minerals) {
        int totalPickCnt = picks[0] + picks[1] + picks[2];

        for (int i = 0; i < minerals.length; i += 5) {
            if (totalPickCnt == 0) {
                break;
            }

            int weight = 0;

            for (int j = i; j < i + 5; j++) {
                if (j >= minerals.length) {
                    break;
                }
                weight += WEIGHTS.get(minerals[j]);
            }
            weights.add(new Data(i, weight));
            totalPickCnt--;
        }
    }

    private String findPickName(final int[] picks) {
        if (picks[0] > 0) {
            picks[0]--;
            return PICK_NAMES[0];
        } else if (picks[1] > 0) {
            picks[1]--;
            return PICK_NAMES[1];
        } else {
            picks[2]--;
            return PICK_NAMES[2];
        }
    }

    static class Data implements Comparable<Data> {

        final int index;
        final int weight;

        public Data(int index, int weight) {
            this.index = index;
            this.weight = weight;
        }

        @Override
        public int compareTo(Data o) {
            return o.weight - this.weight;
        }
    }
}

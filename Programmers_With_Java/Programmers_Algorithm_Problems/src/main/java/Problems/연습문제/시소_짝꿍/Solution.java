package Problems.연습문제.시소_짝꿍;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*

    weight 배열의 개수는 최대 10만개지만
    weight[i]의 범위는 100 <= weight[i] <= 1000 이다.
    weight 배열의 원소의 중복을 제거하면 최대 1000개가 안된다.

    그래서 weight 배열에서 중복을 제거한 list와
    weight[i]마다 중복인 개수를 저장하기 위한 hash map을 구성했다.

    그 후에 중복 제거한 list에서 2개를 선택하는 모든 경우를 확인한다.
    2개를 선택해서 평행이 맞을 때 중복된 개수도 고려해서 개수를 세준다.

    추가적으로 같은 무게끼리도 평행을 이룰 수 있으므로,
    hash map의 각 value가 같은 무게의 사람 수이므로 여기서 2개를 선택하는 경우도 계산해준다.

 */

public class Solution {

    private static final int[] distArr = {2,3,4};

    private Map<Integer, Long> weightCntMap;
    private List<Integer> deDupWeightList;

    public Solution() {
        weightCntMap = new HashMap<>();
        deDupWeightList = new ArrayList<>();
    }

    public void service() {

        int[] weights = {100,180,360,100,270};

        long answer = solution(weights);

        System.out.println(answer);

    }

    public long solution(int[] weights) {

        long answer;

        findWeightCnt(weights);
        makeDeDupWeightList();

        answer = findBalanceCnt();

        return answer;
    }

    private void findWeightCnt(final int[] weights) {
        for (int weight : weights)
            weightCntMap.put(weight, weightCntMap.getOrDefault(weight, 0L) + 1);
    }

    private void makeDeDupWeightList() {
        for (int weight : weightCntMap.keySet())
            deDupWeightList.add(weight);
    }

    private long findBalanceCnt() {

        long balanceCnt = 0;

        for (int i = 0; i < deDupWeightList.size(); i++) {
            for (int j = i + 1; j < deDupWeightList.size(); j++) {

                final int w1 = deDupWeightList.get(i);
                final int w2 = deDupWeightList.get(j);

                if (canBalance(w1, w2) == true)
                    balanceCnt += (weightCntMap.get(w1) * weightCntMap.get(w2));

            }
        }

        for (long weightCnt : weightCntMap.values()) {
            balanceCnt += (weightCnt * (weightCnt - 1) / 2);
        }

        return balanceCnt;
    }

    private boolean canBalance(final int w1, final int w2) {

        for (int i = 0; i < distArr.length; i++)
            for (int j = 0; j < distArr.length; j++)
                if (w1 * distArr[i] == w2 * distArr[j])
                    return true;

        return false;
    }

}

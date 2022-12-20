package Problems.정렬.가장_큰_수;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

/*

    생각의 시작은 숫자를 어느 위치에 넣어야 하는가 이다.
    결국, 각 숫자마다 어느 위치에 넣어야 하는가에 대한 문제로 볼 수 있다.
    그럼 생각해 보면,
    임의의 숫자 2개를 선택했을 때, 2개의 숫자간의 순서는
    그냥 두 숫자를 나열해 봤을 때 큰 숫자가 되는 경우로 정할 수 있다.
    이 순서는 다른 숫자들과는 상관 없이 어떤 상황에서라도 변하지 않는다.
    그렇다면 결국, 숫자들을 이 조건으로 정렬하게 되면 가장 큰 숫자가 되는 형태로 나열된다.

 */

public class Solution {

    private List<Integer> numList;

    public void service() {

        int[] numbers = {6,10,2};

        String answer = solution(numbers);
        System.out.println(answer);

    }

    public String solution(int[] numbers) {

        String answer = "";

        init(numbers);
        sortList();

        if (numList.get(0) == 0) answer = "0";
        else answer = getStringFromList();

        return answer;
    }

    private void init(int[] numbers) {
        numList = Arrays.stream(numbers).boxed().collect(Collectors.toList());
    }

    private void sortList() {
        Collections.sort(numList,
                (Integer o1, Integer o2) -> ((o2.toString() + o1.toString()).compareTo(o1.toString() + o2)));
    }

    private String getStringFromList() {

        StringBuilder stringBuilder = new StringBuilder();

        for (int num : numList)
            stringBuilder.append(num);

        return stringBuilder.toString();
    }

}

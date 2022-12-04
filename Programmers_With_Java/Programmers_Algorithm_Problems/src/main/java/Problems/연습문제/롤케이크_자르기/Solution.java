package Problems.연습문제.롤케이크_자르기;

import java.util.HashMap;
import java.util.Map;

public class Solution {

    private class Rollcake {

        private Map<Integer, Integer> toppingMap = new HashMap<>();

        void addTopping(final int toppingType) {
            toppingMap.put(toppingType, toppingMap.getOrDefault(toppingType, 0) + 1);
        }

        void removeTopping(final int toppingType) {

            int numOfTopping = toppingMap.getOrDefault(toppingType, 0);

            toppingMap.put(toppingType, --numOfTopping);

            if (numOfTopping == 0)
                toppingMap.remove(toppingType);

        }

        int getNumOfToppingType() {
            return toppingMap.size();
        }

    }

    private Rollcake leftPiece;
    private Rollcake rightPiece;

    private void init() {
        leftPiece = new Rollcake();
        rightPiece = new Rollcake();
    }

    private void makeRollcake(final int[] toppings) {
        for (int toppingType : toppings)
            rightPiece.addTopping(toppingType);
    }

    private void cutRollcake(final int toppingType) {
        leftPiece.addTopping(toppingType);
        rightPiece.removeTopping(toppingType);
    }

    private boolean isSameNumOfToppingTypeInAllRollcakePiece() {
        return leftPiece.getNumOfToppingType() == rightPiece.getNumOfToppingType();
    }

    public int solution(int[] topping) {

        // rollcake을 왼쪽 조각과 오른쪽 조각으로 나눠서 생각한다.
        // 처음에는 왼쪽 조각은 없고 오른쪽 조각은 전체 롤케익이다.
        // 토핑을 기준으로 왼쪽부터 한 칸씩 이동하면서 잘라본다.
        // 잘랐을 때 토핑의 종류의 개수를 비교한다.

        int answer = 0;

        init();
        makeRollcake(topping);

        for (int toppingType : topping) {

            cutRollcake(toppingType);

            if (isSameNumOfToppingTypeInAllRollcakePiece() == true)
                answer++;
        }

        return answer;
    }

    public void service() {

        int[] toppings = {1, 2, 1, 3, 1, 4, 1, 2};

        int answer = solution(toppings);
        System.out.println(answer);
    }
}

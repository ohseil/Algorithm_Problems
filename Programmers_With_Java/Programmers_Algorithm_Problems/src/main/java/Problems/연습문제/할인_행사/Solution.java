package Problems.연습문제.할인_행사;

import java.util.HashMap;
import java.util.Map;

public class Solution {

    private Map<String, Integer> needWantProductNumMap = new HashMap<>();
    private Map<String ,Integer> canBuyDiscountProductNumMap = new HashMap<>();

    private void makeNeedProductNumMap(String[] want, int[] number) {

        for (int i = 0; i < want.length; i++) {

            String wantProduct = want[i];
            int wantNum = number[i];

            needWantProductNumMap.put(wantProduct, wantNum);
        }
    }

    private boolean canSignUp() {

        for (String needProduct : needWantProductNumMap.keySet()) {

            int needNum = needWantProductNumMap.get(needProduct);
            int canBuyNum = canBuyDiscountProductNumMap.getOrDefault(needProduct, 0);

            if (canBuyNum != needNum)
                return false;
        }

        return true;
    }


    private int findSignUpDates(String[] discountProducts) {

        int signUpDateNum = 0;

        for (int i = 0; i < discountProducts.length; i++) {

            String discountProduct = discountProducts[i];

            if (needWantProductNumMap.containsKey(discountProduct) == true) {

                int canBuyNum = canBuyDiscountProductNumMap.getOrDefault(discountProduct, 0);
                canBuyDiscountProductNumMap.put(discountProduct, canBuyNum + 1);
            }

            if (i >= 10) {

                String productOutOfRange = discountProducts[i - 10];

                if (needWantProductNumMap.containsKey(productOutOfRange) == true) {

                    int canBuyNum = canBuyDiscountProductNumMap.getOrDefault(productOutOfRange, 0);
                    canBuyDiscountProductNumMap.put(productOutOfRange, canBuyNum - 1);
                }
            }

            if (canSignUp() == true)
                signUpDateNum++;

        }

        return signUpDateNum;
    }

    public int solution(String[] want, int[] number, String[] discount) {

        // 원하는 상품들의 개수를 hash map으로 저장해 놓는다.
        // 연속되는 10일 간의 할인 상품들의 개수를 hash map으로 저장해 놓고
        // 앞서 저장해 놓았던 원하는 상품들의 개수와 비교해서 일치하면 회원 가입 가능한 날짜라고 판단한다.
        // 처음 10일 이후부터는 10일의 범위에 벗어난 이전 상품 데이터를 갱신해 준다.
        int answer = 0;

        makeNeedProductNumMap(want, number);
        answer = findSignUpDates(discount);

        return answer;
    }

    public void service() {

        String[] wants = {"banana","apple","rice","pork","pot"};
        int[] numbers = {3,2,2,2,1};
        String[] discounts = {"chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana"};

        int answer = solution(wants, numbers, discounts);
        System.out.println(answer);
    }
}

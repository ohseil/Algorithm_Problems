package Problems.연습문제.햄버거_만들기;

import java.util.Deque;
import java.util.LinkedList;

public class Solution {

    public void service() {
        final int[] ingredients = {2,1,1,2,3,1,2,3,1};
        final int answer = solution(ingredients);
        System.out.println(answer);
    }

    public int solution(final int[] ingredients) {
        int answer = 0;
        Deque<Integer> stack = new LinkedList();
        int[] pre3Ingredients = new int[3];

        for (int ingredient : ingredients) {
            if (ingredient != 1) {
                stack.addFirst(ingredient);
                updatePre3Ingredients(pre3Ingredients, ingredient);
                continue;
            }

            if (canMakeHamburger(pre3Ingredients, ingredient) == true) {
                for (int i = 0; i < 3; i++) {
                    stack.pollFirst();
                }

                for (int i = 2; i >= 0; i--) {
                    if (stack.isEmpty() == true) {
                        pre3Ingredients[i] = 0;
                    } else {
                        pre3Ingredients[i] = stack.pollFirst();
                    }
                }

                for (int i = 0; i < 3; i++) {
                    stack.addFirst(pre3Ingredients[i]);
                }

                answer++;
            } else {
                stack.addFirst(ingredient);
                updatePre3Ingredients(pre3Ingredients, ingredient);
            }
        }
        return answer;
    }

    private boolean canMakeHamburger(final int[] pre3Ingredients, final int newIngredient) {
        return pre3Ingredients[0] == 1 &&
                (pre3Ingredients[1] == 2) &&
                (pre3Ingredients[2] == 3) &&
                (newIngredient == 1);
    }

    private void updatePre3Ingredients(final int[] pre3Ingredients, final int newIngredient) {
        pre3Ingredients[0] = pre3Ingredients[1];
        pre3Ingredients[1] = pre3Ingredients[2];
        pre3Ingredients[2] = newIngredient;
    }
}

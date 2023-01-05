package Problems.탐욕법_Greedy.큰_수_만들기;

/*

    제일 큰 수가 되기 위해서는
    큰 숫자가 높은 자리에 위치해야 한다.
    그리고 낮은 자리의 숫자가 변하는 것보다 높은 자리의 숫자가 변하는 것이 더 큰 숫자가 된다.
    따라서 가장 높은 자리의 숫자부터 조건을 확인하면서 지워나간다.
    현재 자리의 숫자가 하나 낮은 자리의 숫자보다 작은 경우에 제거한다.
    제거 후에, 제거한 자리부터 확인하는 것이 아니라 제거한 자리보다 높은 자리부터 확인해야 한다.
    제거한 자리보다 낮은 자리의 숫자가 제거한 자리로 이동하면서 제거한 자리보다 높은 자리의 숫자보다 클 수 있기 때문이다.

    이 과정을 거친 후에 만약 k번을 모두 채우지 못했다면
    다음 과정을 진행한다.
    이전 과정을 진행한 후의 수는 각 자리의 숫자들이 내림 차순 형태로 나열된 수가 된다.
    이 때, 남은 제거 횟수만큼 가장 낮은 자리부터 제거한다.

 */

public class Solution {

    public void service() {

        String number = "1924";
        int k = 2;

        String answer = solution(number, k);
        System.out.println(answer);

    }

    public String solution(String number, int k) {

        String answer = "";

        StringBuilder stringBuilder = new StringBuilder(number);

        int idx = 0;

        while (k > 0 && idx < stringBuilder.length() - 1) {

            int num = stringBuilder.charAt(idx);
            int afterNum = stringBuilder.charAt(idx + 1);

            if (num < afterNum) {

                stringBuilder.deleteCharAt(idx);

                if (idx != 0)
                    idx--;

                k--;

            }
            else
                idx++;

        }

        while (k-- > 0) stringBuilder.deleteCharAt(stringBuilder.length() - 1);

        answer = stringBuilder.toString();

        return answer;
    }

}

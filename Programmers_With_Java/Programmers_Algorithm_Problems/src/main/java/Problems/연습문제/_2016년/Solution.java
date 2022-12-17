package Problems.연습문제._2016년;

/*

    구해야 하는 달의 이전 달까지의 일 수를 모두 더한다.
    구해야 하는 일 수를 추가로 더한다. 이것을 x라고 하면,
    일주일에 요일은 7개이고 주기적으로 돌아가는 규칙이기 때문에
    처음 날인 금요일 부터 x % 7 만큼 바뀐 요일이 답이다.

 */

public class Solution {

    private static final String[] daysOfWeek = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
    private static final int[] numsOfDayOfMonth = {0,31,29,31,30,31,30,31,31,30,31,30,31};

    public void service() {

        int a = 5;
        int b = 24;

        String answer = solution(a, b);
        System.out.println(answer);

    }

    public String solution(int a, int b) {

        String answer = "";

        int totalDay = 0;

        for (int month = 1; month < a; month++)
            totalDay += numsOfDayOfMonth[month];

        totalDay += (b - 1);

        answer = daysOfWeek[totalDay % 7];

        return answer;
    }

}

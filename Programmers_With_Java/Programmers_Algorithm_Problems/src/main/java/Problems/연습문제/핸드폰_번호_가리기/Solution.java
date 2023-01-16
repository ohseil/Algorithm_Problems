package Problems.연습문제.핸드폰_번호_가리기;

public class Solution {

    private StringBuilder stringBuilder;

    public Solution() {
        stringBuilder = new StringBuilder();
    }

    public void service() {

        String phone_number = "01033334444";

        String answer = solution(phone_number);
        System.out.println(answer);

    }

    public String solution(String phone_number) {

        String answer = "";

        for (int i = 0; i < phone_number.length() - 4; i++)
            stringBuilder.append("*");
        for (int i = phone_number.length() - 4; i < phone_number.length(); i++)
            stringBuilder.append(phone_number.charAt(i));

        answer = stringBuilder.toString();

        return answer;
    }

}

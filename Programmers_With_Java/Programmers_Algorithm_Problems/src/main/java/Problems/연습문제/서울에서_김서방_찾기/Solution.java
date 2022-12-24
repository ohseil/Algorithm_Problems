package Problems.연습문제.서울에서_김서방_찾기;

public class Solution {

    public void service() {

        String[] seoul = {"Jane", "Kim"};

        String answer = solution(seoul);
        System.out.println(answer);

    }

    public String solution(String[] seoul) {

        String answer = "";

        for (int i = 0; i < seoul.length; i++) {
            if (seoul[i].equals("Kim") == true) {
                answer = "김서방은 " + i + "에 있다";
                break;
            }
        }

        return answer;
    }

}

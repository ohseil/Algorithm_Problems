package Problems.코딩테스트_입문.외계행성의_나이;

public class Solution {

    private static final char[] alphaList = {'a','b','c','d','e','f','g','h','i','j'};

    public void service() {

        int age = 23;

        String answer = solution(age);
        System.out.println(answer);

    }

    public String solution(int age) {

        String answer = "";

        do {

            answer = alphaList[age % 10] + answer;
            age /= 10;

        } while(age > 0);

        return answer;
    }

}

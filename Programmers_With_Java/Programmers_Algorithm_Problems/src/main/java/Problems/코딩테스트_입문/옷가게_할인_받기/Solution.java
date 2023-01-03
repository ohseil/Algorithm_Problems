package Problems.코딩테스트_입문.옷가게_할인_받기;

public class Solution {

    public void service() {

        int price = 150000;

        int answer = solution(price);
        System.out.println(answer);

    }

    public int solution(int price) {

        int answer = 0;

        if (price >= 500000) answer = price * 80 / 100;
        else if (price >= 300000) answer = price * 90 / 100;
        else if (price >= 100000) answer = price * 95 / 100;
        else answer = price;

        return answer;
    }

}

package Problems.위클리_챌린지.부족한_금액_계산하기;

public class Solution {

    public void service() {

        int price = 3;
        int money = 20;
        int count = 4;

        long answer = solution(price, money, count);

        System.out.println(answer);

    }

    public long solution(int price, int money, int count) {

        long answer = 0;
        long needMoney = 0;
        long rideCnt = 1;

        while (count >= rideCnt) {
            needMoney += (price * rideCnt);
            rideCnt++;
        }

        if (needMoney - money < 0) answer = 0;
        else answer = needMoney - money;

        return answer;
    }

}

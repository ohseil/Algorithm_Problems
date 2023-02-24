package Problems.연습문제.기사단원의_무기;

public class Solution {

    public void service() {
        final int number = 5;
        final int limit = 3;
        final int fixedPower = 2;

        final int answer = solution(number, limit, fixedPower);
        System.out.println(answer);
    }

    public int solution(final int number, final int limit, final int fixedPower) {
        int answer = 0;

        for (int i = 0; i <= number; i++) {
            final int needWeaponPower = findNeedWeaponPower(i);

            if (needWeaponPower <= limit) answer += needWeaponPower;
            else answer += fixedPower;
        }
        return answer;
    }

    private int findNeedWeaponPower(final int templar) {
        int weaponPower = 0;

        for (int i = 1; i * i <= templar; i++) {
            if (i * i == templar) weaponPower++;
            else if (templar % i == 0) weaponPower += 2;
        }
        return weaponPower;
    }
}

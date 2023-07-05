package Problems.연습문제.덧칠하기;

/**
 * 풀이 과정의 기반이 되는 생각은 다음과 같다.
 * 가장 왼쪽에 있는 칠해야 할 영역을 칠할 때 가장 효율이 좋게 칠하기 위해서는 이 영역을 롤러의 끝에 맞춰서 칠하는 것이다.
 * 이렇게 칠해야 최대한 많은 영역을 칠할 수 있다.
 * 이 방식으로 칠한 영역들을 표시하고 다음 칠해야 하는 영역에서도 이와 같은 방식으로 칠해나가는 것이 가장 효율적인 방법이다.
 */

public class Solution {

    int[] paintedSections;

    public void service() {
        final int n = 8;
        final int m = 4;
        final int[] sections = {2,3,6};

        final int answer = solution(n, m, sections);
        System.out.println(answer);
    }

    public int solution(int n, int m, int[] sections) {
        int answer = 0;
        paintedSections = new int[n + 1];

        for (int section : sections) {
            if (paintedSections[section] == 1) {
                continue;
            }

            for (int s = section; (s < section + m && s <= n); s++) {
                paintedSections[s] = 1;
            }
            answer++;
        }
        return answer;
    }
}

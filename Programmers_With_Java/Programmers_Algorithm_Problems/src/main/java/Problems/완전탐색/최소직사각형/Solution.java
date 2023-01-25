package Problems.완전탐색.최소직사각형;

import java.util.Arrays;
import java.util.List;

/*

    일단 모든 명함의 가로 세로 중에 가장 긴 길이는 지갑의 한 변으로 선택될 수 밖에 없다.
    각 명함의 가로와 세로 중에 긴 길이를 index 0에 위치시키고 짧은 길이를 index 1에 위치시켰다.
    지갑의 가로가 모든 명함의 길이 중 가장 긴 길이로 선택이 되었다면,
    나머지 세로의 길이는 명함들을 모두 담을 수 있는 가장 짧은 길이를 선택해야 한다.
    그래서 각 명함에서 긴 변을 이미 선택된 가로로 위치시킨다.
    그러면 각 명함에서 짧은 변이 세로의 후보가 된다.
    여기서 각 명함에서 남은 길이 중에 가장 긴 변을 선택한다.

 */

public class Solution {

    private List<int[]> numPairList;

    public void service() {

        int[][] sizes = {{60,50},{30,70},{60,30},{80,40}};

        int answer = solution(sizes);

        System.out.println(answer);

    }

    public int solution(int[][] sizes) {

        int answer = 0;

        classifyBigToLeftAndSmallToRight(sizes);

        numPairList = Arrays.asList(sizes);

        numPairList.sort((lhs, rhs) -> {
            if (lhs[0] > rhs[0]) return -1;
            else if (lhs[0] < rhs[0]) return 1;
            return 0;
        });

        for (int i = 0; i < numPairList.size(); i++) {
            if (answer < numPairList.get(0)[0] * numPairList.get(i)[1])
                answer = numPairList.get(0)[0] * numPairList.get(i)[1];
        }

        return answer;
    }

    private void classifyBigToLeftAndSmallToRight(int[][] sizes) {
        for (int i = 0; i < sizes.length; i++) {
            if (sizes[i][0] < sizes[i][1]) {
                int temp = sizes[i][0];
                sizes[i][0] = sizes[i][1];
                sizes[i][1] = temp;
            }
        }
    }

}

package Problems.정렬.H_Index;

/*

    누적 합을 이용했다.

    먼저 인용 횟수 최대 범위 크기의 배열을 만들고 각 횟수만큼 인용된 논문의 개수를 저장한다.
    가장 많은 횟수부터 시작해서 가장 작은 횟수까지 누적 합을 구한다.
    이렇게 되면 배열의 특정 횟수에 해당하는 값을 참조했을 때, 특정 횟수 이상 인용된 논문의 개수를 구할 수 있다.
    누적 합 배열을 가장 많은 횟수부터 시작해서 확인한다.

 */

public class Solution {

    private static final int MAX_CITATIONS_CNT = 10000;

    public void service() {

        int[] citations = {3,0,6,1,5};

        int answer = solution(citations);
        System.out.println(answer);

    }

    public int solution(int[] citations) {

        int answer = 0;

        int[] prefixSumArr = new int[MAX_CITATIONS_CNT + 1];

        for (int citation : citations)
            prefixSumArr[citation]++;

        for (int i = MAX_CITATIONS_CNT - 1; i >= 0; i --)
            prefixSumArr[i] += prefixSumArr[i + 1];

        for (int i = MAX_CITATIONS_CNT; i >= 0; i--) {
            if (i <= prefixSumArr[i]) {
                answer = i;
                break;
            }
        }

        return answer;
    }

}

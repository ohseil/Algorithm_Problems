package Problems.코딩테스트_입문.특이한_정렬;

public class Solution {

    int arr[];

    public void service() {

        int[] numlist = {1,2,3,4,5,6};
        int n = 4;

        int[] answer = solution(numlist, n);
        for (int a : answer)
            System.out.print(a + " ");

    }

    public int[] solution(int[] numlist, int n) {

        int[] answer = new int[numlist.length];
        int idx = 0;
        int dist = 1;

        init();

        for (int num : numlist)
            arr[num]++;

        if (arr[n] == 1) {
            answer[idx] = n;
            idx++;
        }

        while (idx < numlist.length) {

            if ((n + dist) <= 10000 && arr[n + dist] > 0) {
                answer[idx] = n + dist;
                idx++;
            }

            if ((n - dist) >= 0 && arr[n - dist] > 0) {
                answer[idx] = n - dist;
                idx++;
            }

            dist++;

        }

        return answer;
    }

    private void init() {
        arr = new int[10001];
    }

}

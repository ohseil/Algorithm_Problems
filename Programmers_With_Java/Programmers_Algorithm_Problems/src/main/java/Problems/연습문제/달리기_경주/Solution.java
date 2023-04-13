package Problems.연습문제.달리기_경주;

import java.util.HashMap;
import java.util.Map;

public class Solution {

    private final Map<String, Integer> posMap = new HashMap<>();

    public void service() {
        final String[] players = {"mumu", "soe", "poe", "kai", "mine"};
        final String[] callings = {"kai", "kai", "mine", "mine"};

        final String[] answer = solution(players, callings);
        for (String a : answer) {
            System.out.print(a + " ");
        }
        System.out.println();
    }

    public String[] solution(final String[] players, final String[] callings) {
        String[] answer = {};

        findPlayerPos(players);

        for (String calledName : callings) {
            overtake(players, calledName);
        }

        answer = players;
        return answer;
    }

    private void findPlayerPos(final String[] players) {
        for (int i = 0; i < players.length; i++) {
            posMap.put(players[i], i);
        }
    }

    private void overtake(final String[] players, final String calledName) {
        int pos = posMap.get(calledName);

        if (pos == 0) {
            return;
        }
        swap(players, pos, pos - 1);
        posMap.put(players[pos], pos);
        posMap.put(players[pos - 1], pos - 1);
    }

    private void swap(final String[] players, final int idx1, final int idx2) {
        String temp = players[idx1];
        players[idx1] = players[idx2];
        players[idx2] = temp;
    }
}

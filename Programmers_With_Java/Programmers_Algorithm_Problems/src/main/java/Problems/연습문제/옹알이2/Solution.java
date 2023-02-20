package Problems.연습문제.옹알이2;

public class Solution {

    public void service() {
        final String[] babbling = {"aya", "yee", "u", "maa"};
        final int answer = solution(babbling);
        System.out.println(answer);
    }

    public int solution(final String[] babbling) {
        int answer = 0;

        for (String word : babbling) {
            if (canBabbling(word)) {
                answer++;
            }
        }
        return answer;
    }

    private boolean canBabbling(final String word) {
        int idx = 0;
        String preMatchWord = "default";

        while (idx < word.length()) {
            String matchWord = findMatchWord(word.charAt(idx));

            if (matchWord == null ||
                    (matchWord.equals(preMatchWord)) ||
                    (idx + matchWord.length() - 1 >= word.length()) ||
                    (!word.substring(idx, idx + matchWord.length()).equals(matchWord))) {
                return false;
            }

            idx += matchWord.length();
            preMatchWord = matchWord;
        }
        return true;
    }

    private String findMatchWord(final char ch) {
        if (ch == 'a') {
            return "aya";
        } else if (ch == 'y') {
            return "ye";
        } else if (ch == 'w') {
            return "woo";
        } else if (ch == 'm') {
            return "ma";
        } else {
            return null;
        }
    }
}

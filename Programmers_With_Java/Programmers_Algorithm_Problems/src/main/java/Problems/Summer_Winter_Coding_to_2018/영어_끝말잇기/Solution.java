package Problems.Summer_Winter_Coding_to_2018.영어_끝말잇기;

import java.util.HashSet;
import java.util.Set;

public class Solution {

    private int turns[];
    private Set<String> usedWords;
    private String lastUsedWord;

    private void init(int n, String firstWord) {
        turns = new int[n + 1];
        usedWords = new HashSet<>();
        lastUsedWord = firstWord.substring(0, 1);
    }


    private boolean isSatisfyConditions(String word) {
        if (word.length() < 2) return false;
        if (word.charAt(0) != lastUsedWord.charAt(lastUsedWord.length() - 1)) return false;
        if (usedWords.contains(word) == true) return false;
        return true;
    }

    public int[] solution(int n, String[] words) {

        // 단어를 말했을 때 틀리는 조건
        // 1. 단어의 길이가 2 미만인 경우
        // 2. 1을 만족하지만 마지막 단어의 마지막 알파벳과 단어의 첫 번째 알파벳이 일치하지 않는 경우
        // 3. 1과 2를 만족하지만 이미 말한 단어인 경우

        // 위 조건들을 검사하기 위해,
        // hash set과 마지막 단어를 저장할 string 변수 lastWord를 사용한다.
        // hash set에는 말했던 단어들이 저장되어 있고,
        // lastWord에는 마지막에 말한 단어가 저장되어 있다.

        // 각 차례에 말하는 사람의 번호는 단어의 (index % n + 1)이다.
        // 사람의 번호는 범위가 정해져 있기 때문에 배열 turns[n]을 사용한다.
        // 차례마다 turns[index%n+1]++을 한다.

        int[] answer = {0, 0};

        init(n, words[0]);

        for (int i = 0; i < words.length; i++) {

            int pnum = i % n + 1;
            int pturn = ++turns[pnum];
            String word = words[i];

            if (isSatisfyConditions(word) == false) {
                answer = new int[]{pnum, pturn};
                break;
            }

            lastUsedWord = word;
            usedWords.add(word);
        }

        return answer;
    }

    public void service() {

        int n = 3;
        String words[] = {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"};

        int answer[] = solution(n, words);
        System.out.println(answer[0] + " " + answer[1]);
    }

}

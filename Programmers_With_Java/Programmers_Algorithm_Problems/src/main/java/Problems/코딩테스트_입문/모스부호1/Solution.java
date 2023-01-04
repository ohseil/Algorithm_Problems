package Problems.코딩테스트_입문.모스부호1;

import java.util.HashMap;
import java.util.Map;

public class Solution {

    private Map<String, Character> morsecodeMap;

    public void service() {

        String letter = ".... . .-.. .-.. ---";

        String answer = solution(letter);
        System.out.println(answer);

    }

    public String solution(String letter) {

        String answer = "";

        init();

        String[] morsecodes = letter.split(" ");

        for (String morsecode : morsecodes)
            answer += morsecodeMap.get(morsecode);

        return answer;
    }

    private void init() {

        morsecodeMap = new HashMap<String, Character>() {{
            put(".-", 'a'); put("-...", 'b'); put("-.-.", 'c');
            put("-..", 'd'); put(".", 'e'); put("..-.", 'f');
            put("--.", 'g'); put("....", 'h'); put("..", 'i');
            put(".---", 'j'); put("-.-", 'k'); put(".-..", 'l');
            put("--", 'm'); put("-.", 'n'); put("---", 'o');
            put(".--.", 'p'); put("--.-", 'q'); put(".-.", 'r');
            put("...", 's'); put("-", 't'); put("..-", 'u');
            put("...-", 'v'); put(".--", 'w'); put("-..-", 'x');
            put("-.--", 'y'); put("--..", 'z');
        }};

    }

}

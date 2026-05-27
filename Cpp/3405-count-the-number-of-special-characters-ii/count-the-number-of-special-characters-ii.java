class Solution {
    public int numberOfSpecialChars(String word) {

        Map<Character, Integer> lastIdxSmallChar = new HashMap<>();
        Map<Character, Integer> firstIdxLargeChar = new HashMap<>();

        for(int i = 0; i < word.length(); i++) {

            if(word.charAt(i) >= 'a' && word.charAt(i) <= 'z') {

                lastIdxSmallChar.put(word.charAt(i), i);

            } else {

                if(!firstIdxLargeChar.containsKey(word.charAt(i)))
                    firstIdxLargeChar.put(word.charAt(i), i);
            }
        }

        int special = 0;

        for(char key : lastIdxSmallChar.keySet()) {

            char capital = (char)(key - 32);

            if(!firstIdxLargeChar.containsKey(capital)) continue;

            int idxSmallChar = lastIdxSmallChar.get(key);
            int idxCapitalChar = firstIdxLargeChar.get(capital);

            if(idxSmallChar < idxCapitalChar)
                special++;
        }

        return special;
    }
}
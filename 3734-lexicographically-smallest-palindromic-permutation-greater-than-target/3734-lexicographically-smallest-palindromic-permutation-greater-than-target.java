class Solution {
    public String lexPalindromicPermutation(String s, String target) {
        int[] freq = new int[26];
        for (int i = 0; i < s.length(); i++)
            freq[s.charAt(i) - 'a']++;

        char center = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                if (center != 0)
                    return "";
                center = (char) ('a' + i);
                freq[i]--;
            }
        }

        int sz = s.length();
        int half = sz / 2;
        for (int i = 0; i < half; i++)
            freq[target.charAt(i) - 'a'] -= 2;

        if (check(freq)) {
            String head = target.substring(0, half);
            String rev = new StringBuilder(head).reverse().toString();
            String tail = "";
            if (center != 0)
                tail += center;
            tail += rev;
            if (tail.compareTo(target.substring(half)) > 0)
                return head + tail;
        }

        for (int i = half - 1; i >= 0; i--) {
            char w = target.charAt(i);
            freq[w - 'a'] += 2;
            if (!check(freq))
                continue;

            for (int j = (w - 'a') + 1; j < 26; j++) {
                if (freq[j] == 0)
                    continue;
                freq[j] -= 2;
                StringBuilder answer = new StringBuilder(target.substring(0, i + 1));
                answer.setCharAt(i, (char) ('a' + j));

                for (int k = 0; k < 26; k++) {
                    int cnt = freq[k] / 2;
                    for (int m = 0; m < cnt; m++)
                        answer.append((char) ('a' + k));
                }

                String part = new StringBuilder(answer).reverse().toString();
                if (center != 0)
                    answer.append(center);
                answer.append(part);
                return answer.toString();
            }
        }

        return "";
    }

    boolean check(int[] freq) {
        for (int v : freq)
            if (v < 0)
                return false;
        return true;
    }
}
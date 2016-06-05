public class Solution {
    public String minWindow(String s, String t) {
        if (t.length() > s.length() || s.length() == 0 || t.length() == 0) {
            return "";
        }
        int map[] = new int[256];
        int window[] = new int[256];
        int fast, slow = 0, len = 0;
        int maxLen = Integer.MAX_VALUE;
        String res = "";
        for (int i = 0; i < t.length(); i++) {
            map[t.charAt(i)]++;
        }
        for (fast = 0; fast < s.length(); fast++) {
            char c = s.charAt(fast);
            if (map[c] > 0) {
                window[c]++;
                if (window[c] <= map[c]) {
                    len++;
                }
            }
            if (len >= t.length()) {
                if (s.charAt(slow) == 'B') {
                }
                while (map[s.charAt(slow)] == 0 || window[s.charAt(slow)] > map[s.charAt(slow)]) {
                    if (map[s.charAt(slow)] > 0) {
                        window[s.charAt(slow)]--;
                    }
                    slow++;
                }
                if (fast - slow + 1 < maxLen) {
                    maxLen = fast - slow + 1;
                    res = s.substring(slow, fast + 1);
                }
            }
        }
        return res;
    }
}

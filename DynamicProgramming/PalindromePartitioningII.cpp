public class Solution {
    public int minCut(String s) {
        int[] cut = new int[s.length()+1];
        for (int i = 1; i <= s.length(); i++) {
            cut[i] = i - 1;
        }
        boolean [][] isPalindrome = new boolean [s.length()][s.length()];
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j >= 0; j--) {
                if (s.charAt(i) == s.charAt(j) &&  (i - j < 2 || isPalindrome[j+1][i-1])) {
                    isPalindrome[j][i] = true;
                    if (j == 0) {
                        cut[i+1] = 0;
                    }
                    else {
                        cut[i+1] = Math.min(cut[i+1], cut[j] + 1);
                    }
                }
            }
        }
        return cut[s.length()];
    }
}

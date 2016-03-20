class Solution {
    string expandPalindrome(string s, int l, int r) {
        int n = s.size();
        while(s[l] == s[r] && l >= 0 && r < n) {
            l--;
            r++;
        }
        return s.substr(l+1, r-l-1);
    }
public:
    string longestPalindrome(string s) {
        string pal = s.substr(0, 1);
        string temp;
        for(int i = 0; i < s.size()-1; i++) {
            temp = expandPalindrome(s, i, i);
            if(temp.size() > pal.size()) {
                pal = temp;
            }
            temp = expandPalindrome(s, i, i+1);
            if(temp.size() > pal.size()) {
                pal = temp;
            }
        }
        return pal;
    }
};

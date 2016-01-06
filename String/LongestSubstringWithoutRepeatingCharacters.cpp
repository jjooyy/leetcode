class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charmap(256, -1);
        int count = 0;
        int max = 0;
        int size = s.size();
        int head = 0;
        int end = 0;
        while(end != size) {
            if(charmap[s[end]] == -1) {
                charmap[s[end]] = end;
                end++;
            }
            else {
                count = end - head;
                if(count > max) {
                    max = count;
                }
                if(head < charmap[s[end]] + 1) {
                    head = charmap[s[end]] + 1; 
                }

                charmap[s[end]] = end;
                end++;
            }
        }
        count = size - head;
        if(count > max) {
            max = count;
        }
        return max;
    }
};

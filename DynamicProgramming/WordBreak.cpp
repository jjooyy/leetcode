class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(s.size() == 0 || wordDict.size() == 0) {
            return false;
        }
        int size = s.size();
        vector<bool> brk(size+1);
        brk[0] = true;
        int minlen = INT_MAX;
        int maxlen = 0;
        for(string word : wordDict) {
            if(word.size() > maxlen) {
                maxlen = word.size();
            }
            if(word.size() < minlen) {
                minlen = word.size();
            }
        }
        for(int i = 1; i <= size; i++) {
            if(i < minlen) {
                brk[i] = false;
            }
            else {
                for(int j = minlen; j <= min(maxlen, i); j++) {
                    if(brk[i - j] && wordDict.find(s.substr(i - j, j)) != wordDict.end()){
                        brk[i] = true;
                        break;
                    }
                }
            }
        }
        return brk[size];
    }
};

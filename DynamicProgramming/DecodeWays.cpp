class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        if(!size)
            return 0;
        char pre = s[0];
        vector<int> ways(size);
        if(s[0] != '0')
            ways[0] = 1;
        else 
            return 0;
        for(int i = 1; i < size; i++) {
            if(s[i] == '0') {
                if(s[i-1] == '1' || s[i-1] == '2') {
                    if(i>1) {
                        ways[i] = ways[i-2];
                    }
                    else 
                        ways[i] = 1;
                }
                else {
                    return 0;
                }
            }
            else {
                if(s[i-1] == '0' || s[i-1] > '2') {
                    ways[i] = ways[i-1];
                }
                else {
                    if(s[i-1] == '2' && s[i] >='7') {
                        ways[i] = ways[i-1];
                    }
                    else {
                        ways[i] = ways[i-1];
                        if(i > 1) {
                            ways[i] += ways[i-2];
                        }
                        else {
                            ways[i]++;
                        }
                    }
                }
            }
        }
        return ways[size - 1];
    }
};

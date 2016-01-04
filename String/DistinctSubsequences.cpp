class Solution {
public:
    int numDistinct(string s, string t) {
        int sizes = s.size();
        int sizet = t.size();
        vector<vector<int>> map(sizet+1, vector<int>(sizes+1, 0));
        for(int i = 0; i <= sizes; i++) {
            map[0][i] = 1;
        }
        
        for(int i = 0; i < sizet; i++) {
            for(int j = 0; j < sizes; j++) {
                if(t[i] == s[j]) {
                    map[i+1][j+1] = map[i][j] + map[i+1][j];
                }
                else {
                    map[i+1][j+1] = map[i+1][j];
                }
            }
        }
        return map[sizet][sizes];
    }
};

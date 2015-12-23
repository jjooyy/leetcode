class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        vector<vector<int>> dis(size1+1, vector<int>(size2+1, 0));
        for(int i = 0; i <= size1; i++) {
            dis[i][0] = i;
        }
        for(int i = 1; i <= size2; i++) {
            dis[0][i] = i;
        }
        for(int i = 1; i <= size1; i++) {
            for(int j = 1; j <= size2; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dis[i][j] = dis[i-1][j-1];
                }
                else {
                    dis[i][j] = min(dis[i-1][j] + 1, min(dis[i][j-1] + 1, dis[i-1][j-1] + 1));
                }
            }
        }
        return dis[size1][size2];
    }
};

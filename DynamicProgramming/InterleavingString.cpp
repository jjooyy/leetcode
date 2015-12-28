class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int size1 = s1.size();
        int size2 = s2.size();
        int size3 = s3.size();
        if(size3 != size1 + size2) {
            return false;
        }
        vector<vector<bool>> isInter(size1+1, vector<bool>(size2+1));
        for(int i = 0; i <= size1; i++) {
            for(int j = 0; j <= size2; j++) {
                if(i == 0 && j == 0) {
                    isInter[i][j] = true;
                }
                else if(i == 0) {
                    isInter[i][j] = isInter[i][j-1] && s2[j-1] == s3[i+j-1];
                }
                else if(j == 0) {
                    isInter[i][j] = isInter[i-1][j] && s1[i-1] == s3[i+j-1];
                }
                else {
                    isInter[i][j] = (isInter[i-1][j] && s1[i-1] == s3[i+j-1]) || ( isInter[i][j-1] && s2[j-1] == s3[i+j-1]);
                }
            }
        }
        return isInter[size1][size2];
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(!row) {
            return 0;
        }
        int col = matrix[0].size();
        if(!col) {
            return 0;
        }
        int maxLen = 0;
        vector<vector<int>>square(row, vector<int>(col));
        for(int i = 0; i < row; i++) {
            square[i][0] = matrix[i][0] - '0';
            if(maxLen == 0 && matrix[i][0] == '1') {
                maxLen = 1;
            }
        }
        for(int j = 0; j < col; j++) {
            square[0][j] = matrix[0][j] - '0';
            if(maxLen == 0 && matrix[0][j] == '1') {
                maxLen = 1;
            }
        }
        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                if(matrix[i][j] == '1') {
                    square[i][j] = min(square[i][j-1], min(square[i-1][j], square[i-1][j-1])) + 1;
                    maxLen = max(maxLen, square[i][j]);
                }
                else {
                    square[i][j] = 0;
                }
            }
        }
        return maxLen * maxLen;
    }
};

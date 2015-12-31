class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n,0));
        if(!n) {
            return matrix;
        }
        int rowStart = 0;
        int rowEnd = n - 1;
        int colStart = 0;
        int colEnd = n - 1;
        int count = 1;
        
        while(rowStart <= rowEnd && colStart <= colEnd) {
            for(int i = colStart; i <= colEnd; i++) {
                matrix[rowStart][i] = count++;
            }
            rowStart++;
            if(colStart <= colEnd) {
                for(int i = rowStart; i <= rowEnd; i++) {
                    matrix[i][colEnd] = count++;
                }
                colEnd--;
            }
            if(rowStart <= rowEnd && colStart <= colEnd) {
                for(int i = colEnd; i >= colStart; i--) {
                    matrix[rowEnd][i] = count++;
                }
                rowEnd--;
            }
            if(rowStart <= rowEnd && colStart <= colEnd) {
                for(int i = rowEnd; i >= rowStart; i--) {
                    matrix[i][colStart] = count++;
                }
                colStart++;
            }
        }
        return matrix;
    }
};

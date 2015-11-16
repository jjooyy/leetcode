class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        if(!row) {
            return 0;
        }
        else {
            int col = grid[0].size();
            vector<vector<int>> minPathSum(row, vector<int>(col));
            for(int i = 0; i < row; i++) {
                for(int j = 0; j < col; j++) {
                    if(i==0 && j == 0) {
                        minPathSum[i][j] = grid[i][j];
                    }
                    else if(i == 0 ) {
                        minPathSum[i][j] = grid[i][j] + minPathSum[i][j-1];
                    }
                    else if(j == 0) {
                        minPathSum[i][j] = grid[i][j] + minPathSum[i-1][j];
                    }
                    else {
                        minPathSum[i][j] = min(minPathSum[i-1][j] + grid[i][j], minPathSum[i][j-1] + grid[i][j]);
                    }
                }
            }
            return minPathSum[row-1][col-1];
        }
    }
};

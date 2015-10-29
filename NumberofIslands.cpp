class Solution {
public:
    void checkIslands(vector<vector<char>>& grid, int i, int j) {
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]=='0') {
            return;
        }
        grid[i][j]='0';
        checkIslands(grid, i, j+1);
        checkIslands(grid, i, j-1);
        checkIslands(grid, i-1, j);
        checkIslands(grid, i+1, j);
    }
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        if(!row)
            return 0;
        int col=grid[0].size();
        int count = 0;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(grid[i][j]=='1') {
                    checkIslands( grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};

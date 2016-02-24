class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0};
        int col[9][9] = {0};
        int blk[9][9] = {0};
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int b = i / 3 * 3 + j / 3;
                    if(row[i][num] || col[num][j] || blk[b][num]) {
                        return false;
                    }
                    else {
                        row[i][num] = 1;
                        col[num][j] = 1;
                        blk[b][num] = 1;
                    }
                }
            }
        }
        return true;
    }
};

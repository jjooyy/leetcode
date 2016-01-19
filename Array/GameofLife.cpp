class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        if(!row) {
            return;
        }
        int col = board[0].size();
        if(!col) {
            return;
        }
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                int count = 0;
                for(int ii = max(0, i - 1); ii <= min(i+1, row-1); ii++) {
                    for(int jj = max(0, j - 1); jj <= min(j+1, col-1); jj++) {
                        if(!(ii == i && jj == j)) {
                            //printf("board[%d][%d]\n", ii, jj);
                            if(board[ii][jj] & 1) {
                                count++;
                            }
                        }
                    }
                }
                //printf("count[%d][%d] %d\n", i, j, count);
                if(board[i][j]) {
                    if(count == 2 || count == 3) {
                         //printf("board[%d][%d] live \n", i, j);
                        board[i][j] |= 2;
                    }
                }
                else {
                    if(count == 3) {
                        board[i][j] |= 2;
                    }
                }
            }
        }
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                board[i][j] >>= 1;
            }
        }
    }
};

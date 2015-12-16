class Solution {
public:
    void changeO(vector<vector<char>>& board, int x, int y, int row, int col) {
        if(x < 0 || x >= row || y < 0 || y >= col || board[x][y] != 'O') {
            return;
        }
        queue<vector<int>> region;
        vector<int> coord({x, y});
        region.push(coord);
        board[x][y] = 'Y';
        while(!region.empty()) {
            vector<int>top = region.front();
            if((top[0]-1 >= 0) && board[top[0] - 1][top[1]] =='O') {
                top[0]--;
                region.push(top);
                board[top[0]][top[1]] = 'Y';
                top[0]++;
            }
            if(top[0] + 1 < row && board[top[0] + 1][top[1]] =='O') {
                top[0]++;
                region.push(top);
                board[top[0]][top[1]] = 'Y';
                top[0]--;
            }
            if(top[1] - 1 >= 0 && board[top[0]][top[1] - 1] == 'O') {
                top[1]--;
                region.push(top);
                board[top[0]][top[1]] = 'Y';
                top[1]++;
            }
            if(top[1] + 1 < col && board[top[0]][top[1] + 1] == 'O') {
                top[1]++;
                region.push(top);
                board[top[0]][top[1]] = 'Y';
                top[1]--;
            }
            region.pop();
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if((!row) || (!board[0].size())) {
            return;
        }
        int col = board[0].size();
        
        for(int i = 0; i < col; i++) {
            changeO(board, 0, i, row, col);
            changeO(board, row - 1, i, row, col);
        }
        for(int i = 0; i < row; i++) {
            changeO(board, i, 0, row, col);
            changeO(board, i, col - 1, row, col);
        }
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j]  == 'Y') {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

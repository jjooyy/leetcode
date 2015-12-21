class Solution {
    int row, col;
public:
    bool search(string word, vector<vector<char>>& board, int start, int x, int y) {
        int s = word.size();
        if(start == s) {
            return true;
        }
        if(x < 0 || x >= row || y < 0 || y >= col || board[x][y] != word[start]) {
            return false;
        }
        else {
            board[x][y] = '0';
            if (search(word, board, start + 1, x-1, y)||search(word, board, start + 1, x+1, y)||
            search(word, board, start + 1, x, y-1)||search(word, board, start + 1, x, y+1)) {
                return true;
            }
            else {
                board[x][y] = word[start];
                return false;
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(!board.size()) {
            return false;
        }
        else if(!board[0].size()) {
            return false;
        }
        else if(!word.size()) {
            return true;
        }
        row = board.size();
        col = board[0].size();
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] == word[0]) {
                    board[i][j] = '0';
                    if(search(word, board, 1, i-1, j)||search(word, board, 1, i+1, j)||
                        search(word, board, 1, i, j-1)||search(word, board, 1, i, j+1)) {
                        return true;
                    }
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }
};

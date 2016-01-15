class Solution {
public:
    int numSquares(int n) {
        if(n <= 0) {
            return 0;
        }
        vector<int> square(n, INT_MAX);
        int sq = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j * j <= i; j++) {
                if(square[i-1] > square[i-1-j*j] + 1) {
                    square[i-1] = square[i-1-j*j] + 1;
                }
            }
        }
        return square[n-1];
    }
};

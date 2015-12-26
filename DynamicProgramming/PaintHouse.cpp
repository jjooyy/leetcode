class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int size = costs.size();
        if(!size) {
            return 0;
        }
        vector<vector<int>> sum(size, vector<int>(3, 0));
        for(int i = 0; i < 3; i++) {
            sum[0][i] = costs[0][i];
        }
        for(int i = 1; i < size; i++) {
            for(int j = 0; j < 3; j++) {
                if(j == 0) {
                    sum[i][j] = min(sum[i-1][1], sum[i-1][2]) + costs[i][j];
                }
                else if (j == 1) {
                    sum[i][j] = min(sum[i-1][0], sum[i-1][2]) + costs[i][j];

                }
                else {
                    sum[i][j] = min(sum[i-1][0], sum[i-1][1]) + costs[i][j];

                }
            }
        }
        return min(sum[size-1][0], min(sum[size-1][1], sum[size-1][2]));
    }
};

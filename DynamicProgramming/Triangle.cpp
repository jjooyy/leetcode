class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int s=triangle.size();
        if(s <= 0)
            return 0;
        vector<int> sum = triangle[s-1];
        for(int i = s-2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                sum[j] = min(sum[j], sum[j+1]) + triangle[i][j];
            }
        }
        return sum[0];
    }
};

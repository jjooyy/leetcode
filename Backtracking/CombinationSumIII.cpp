class Solution {
    
public:
    void getCombinationSum(vector<vector<int>> &com, vector<int>&v, int start, int n, int sum, int vsum) {
        int total = vsum;
        int size = v.size();
        if(size == n) {
            if(vsum == sum) {
                com.push_back(v);
            }
            return;
        }
        for(int i = start; i < 10 && vsum + i <=sum; i++) {
            v.push_back(i);
            getCombinationSum(com, v, i+1, n, sum, vsum+i);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> com;
        vector<int> v;
        if(n <= 0 || n > k * 9) {
            return com;
        }
        getCombinationSum(com, v, 1, k, n, 0);
        return com;
    }
};
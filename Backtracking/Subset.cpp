class Solution {
public:
    void subsetsHelper(vector<vector<int>> &subset, vector<int> &set, vector<int> nums, int setSize, int rs, int start) {
        if(setSize == rs) {
            subset.push_back(set);
        }
        else {
            int size = nums.size();
            for(int i = start; i < size; i++) {
                set.push_back(nums[i]);
                subsetsHelper(subset, set, nums, setSize + 1, rs, i + 1);
                set.pop_back();
            }
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        vector<int> set;
        vector<vector<int>> subset;
        subset.push_back(set);
        sort(nums.begin(), nums.end());
        for(int i = 1; i <= size; i++) {
            for (int j=0; j <= size - i; j++) {
                set.push_back(nums[j]);
                subsetsHelper(subset, set, nums, 1, i, j + 1);
                set.pop_back();
            }
        }
        return subset;
    }
};

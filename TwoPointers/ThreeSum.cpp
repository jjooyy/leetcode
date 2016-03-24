class Solution {
public:
    void check2Sum(vector<int> nums, int start, int sum, vector<vector<int>> &numSet) {
        int head = start + 1;
        int size = nums.size();
        int end = size - 1;
        if(start >= size -2) {
            return;
        }
        while(head < end) {
            int s = nums[head] + nums[end];
            if(sum == s) {
                vector<int> set(3);
                set[0] = nums[start];
                set[1] = nums[head++];
                set[2] = nums[end--];
                numSet.push_back(set);
                while(nums[head]==set[1] && head < end) {
                    head++;
                }
                while(nums[end] == set[2] && head < end) {
                    end--;
                }
            }
            else if(sum > s) {
                head++;
            }
            else {
                end--;
            }
        }
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> numsVec;
        int size = nums.size();
        if(size < 3) {
            return numsVec;
        }
        else {
            sort(nums.begin(), nums.end());
            for(int i = 0; i < size; i++) {
                if(nums[i] > 0) {
                    break;
                }
                check2Sum(nums, i, -nums[i], numsVec);
                while(i + 1 < size && nums[i] == nums[i+1]) {
                    i++;
                }
            }
            return numsVec;
        }
    }
};

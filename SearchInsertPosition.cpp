class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = nums.size();
        if(s == 1) {
            if(target > nums[0]) {
                return 1;
            }
            else 
                return 0;
        }
        int low = 0;
        int high = s - 1;
        while(low <= high) {
            int mid = (low + high)/ 2;
            if(target < nums[mid])
                high = mid - 1;
            else if(target > nums[mid]) {
                low = mid + 1;
            }
            else {
                return mid;
            }
        }
    }
};

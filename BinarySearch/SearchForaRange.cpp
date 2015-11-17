class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> range(2, -1);
        
        if(size == 1) {
            if(target == nums[0]) {
                range[0] = range[1] = 0;
            }
            else {
                range[0] = range[1] = -1;
            }
            return range;
        }
        
        int low = 0;
        int high = size - 1;
        int mid = 0;
        int newlow, newhigh;
        while(low <= high) {
            mid = (low + high) / 2;
            if(nums[mid] == target) {
                range[0] = range[1] = mid;
                break;
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            }
            else if(nums[mid] > target) {
                high = mid - 1;
            }
        }
        if(nums[mid] != target) {
            return range;
        }
        low = 0;
        high = mid;
        while(low <= high) {
            newlow = (low + high) / 2;
            if(target == nums[newlow]) {
                high = newlow - 1;
            }
            else {
                low = newlow + 1;
            }
        }
        range[0] = low;
        low = mid;
        high = size - 1;
        while(low <= high) {
            newhigh = (low + high) / 2;
            if(target == nums[newhigh]) {
                low = newhigh + 1;
            }
            else {
                high = newhigh -1;
            }
        }
        range[1] = high;
    }
};
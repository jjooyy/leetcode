class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        int low = 0;
        int high = size - 1;
        int mid;
        while(low <= high) {
            mid = (low + high) / 2;
            if(nums[mid] == target) {
                return true;
            }
            else {
                if(nums[mid] == nums[low]) {
                    while(mid > low && nums[mid] == nums[low]) {
                        mid--;
                    }
                    if(mid == low) {
                        if(target == nums[mid]) {
                            return true;
                        }
                        else {
                            low = mid + 1;
                            continue;
                        }
                    }
                    if(nums[mid] == target) {
                        return true;
                    }
                }
                if(nums[mid] > nums[low]) {
                    if(target < nums[low] || target > nums[mid]) {
                        low = mid + 1;
                    }
                    else {
                        high = mid - 1;
                    }
                }
                else{
                    if(target > nums[mid] && target <= nums[high]) {
                        low = mid + 1;
                    }
                    else {
                        high = mid - 1;
                    }
                }
            }
        }
        return false;
    }
};

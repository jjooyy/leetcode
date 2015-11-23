class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        if(!size) {
            return 0;
        }
        int head = 0;
        int end = size - 1;
        int mid;
        while(head < end) {
            mid = (head + end) / 2;
            if(nums[mid] >= nums[head] && nums[mid] > nums[end]) {
                head = mid + 1;
            }
            else {
                end = mid;
            }
        }
        return nums[head];
    }
};

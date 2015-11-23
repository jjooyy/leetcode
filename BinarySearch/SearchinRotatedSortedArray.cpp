class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if(size < 3) {
            if(!size) {
                return -1;
            }
            else {
                for(int i = 0; i < size; i++) {
                    if(nums[i] == target) {
                        return i;
                    }
                }
                return -1;
            }
        }
        else {
            int head = 0;
            int end = size - 1;
            int mid;
            while(head <= end) {
                mid = (head + end)/2;
                if(nums[mid] == target) {
                    return mid;
                }
                if(nums[mid] < nums[end]) {
                    if(target > nums[mid] && target <= nums[end]) {
                        head = mid + 1;
                    }
                    else {
                        end = mid - 1;
                    }
                }
                else {
                  if(target < nums[mid] && target >= nums[head]) {
                      end = mid - 1;
                  }  
                  else {
                      head = mid + 1;
                  }
                }
            }
            return -1;
        }
    }
};

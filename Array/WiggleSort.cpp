class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() == 0) {
            return;
        }
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int temp;
        for(int i = 0; i * 2 + 2 < size; i++) {
            temp = nums[i*2+1];
            nums[i*2+1] = nums[i*2+2];
            nums[i*2+2] = temp;
        }
    }
};

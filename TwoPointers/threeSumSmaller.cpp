class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int count = 0;
        if(nums.size() < 3) {
            return 0;
        }
        int sum[3];
        int s;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++) {
            sum[0] = i;
            sum[1] = i + 1;
            sum[2] = nums.size() - 1;
            while(sum[1] < sum[2]) {
              s = nums[sum[0]] + nums[sum[1]] + nums[sum[2]];
              if(s < target) {
                  count += sum[2] - sum[1];
                  sum[1]++;
              }
              else {
                  sum[2]--;
              }
            }
        }
        return count;
    }
};

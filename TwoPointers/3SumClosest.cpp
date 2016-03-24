class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int close = 0;
        vector<int> sum(3, 0);        
        if(nums.size() < 3) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1;
        int s;
        for(int i = 0; i < n - 1; i++) {
            sum[0] = i;
            sum[1] = i + 1;
            sum[2] = n;
            while(sum[1] < sum[2]) {
              s = nums[sum[0]] + nums[sum[1]] + nums[sum[2]];
              if(s == target) {
                  return target;
              }
              else if(s > target) {
                  if(abs(target - s) < diff) {
                     diff = abs(target - s);
                     close = s;
                  }
                  sum[2]--;
              }
              else {
                  if(abs(target - s) < diff) {
                      diff = abs(target - s);
                      close = s;
                  }
                  sum[1]++;
              }
            }
        }
        return close;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>numsMap;
        vector<int> two;
        int s = nums.size();
        for(int i = 0; i < s; i++) {
            if(numsMap.find(target - nums[i])!=numsMap.end()) {
                two.push_back(numsMap[target-nums[i]] + 1);
                two.push_back(i+1);
                break;
            }
            numsMap.insert({nums[i], i});
        }
        return two;
    }
};

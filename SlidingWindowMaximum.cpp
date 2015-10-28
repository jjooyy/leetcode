class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int idx;
        idx = 0;
        int s = nums.size();
        if(!s) {
            vector<int> max;
            return max;
        }
        deque<int> queue;
        queue.push_back(nums[0]);
        vector<int> max(s-k+1);
        for(int i=1; i<k; i++) {
            if(nums[i]>queue.front()) {
                queue.push_back(nums[i]);
                idx = i;
                queue.pop_front();
            }
        }
        max[0]=queue.front();
        for(int i=k; i<s; i++) {
            if(nums[i]>queue.front()) {
                queue.push_back(nums[i]);
                idx = i;
                queue.pop_front();
            }
            if(idx==i-k) {
                queue.pop_front();
                queue.push_back(nums[i-k+1]);
                idx = i-k+1;
                for(int j=i-k+2; j<=i; j++) {
                    if(nums[j]>queue.front()) {
                        queue.push_back(nums[j]);
                        idx = j;
                        queue.pop_front();
                    }
                }
            }
            max[i-k+1]=queue.front();
        }
        return max;
    }
};
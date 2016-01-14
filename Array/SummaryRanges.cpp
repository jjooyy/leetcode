class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> sum;
        int size = nums.size();
        if(!size) {
            return sum;
        }
        int start = -1;
        int count = -1;
        for(int i = 0; i < size; i++) {
            if(start == -1) {
                start = nums[i];
                count = start + 1;
            }
            else {
                if(nums[i] == count) {
                    count++;
                }
                else {
                    if(count - start == 1) {
                        sum.push_back(to_string(start));
                    }
                    else {
                        string temp = to_string(start) + "->" + to_string(count - 1);
                        sum.push_back(temp);
                    }
                    start = nums[i];
                    count = start + 1;
                }
            }
        }
        if(start == nums[size - 1]) {
            sum.push_back(to_string(start));
        }
        else {
            string temp = to_string(start) + "->" + to_string(count - 1);
            sum.push_back(temp);  
        }
        return sum;
    }
};

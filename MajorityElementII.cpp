class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int s = nums.size();
        vector<int> maj;
        int count1 = 0;
        int count2 = 0;
        int med1, med2;

        for(int i=0; i<s; i++) {
            if(med1==nums[i])
                count1++;
            else if(med2==nums[i])
                count2++;
            else if(!count1) {
                med1 = nums[i];
                count1++;
            }
            else if(!count2) {
                med2 = nums[i];
                count2++;
            }

            else {
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for(int i=0; i<s; i++) {
            if(nums[i]==med1)
                count1++;
            if(nums[i]==med2)
                count2++;
        }
        if(count1>s/3)
            maj.push_back(med1);
        if(count2>s/3)
            maj.push_back(med2);
        return maj;
    }
};

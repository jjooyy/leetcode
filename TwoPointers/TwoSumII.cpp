class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size();
        int low = 0;
        int high = size - 1;
        vector<int> index;
        int sum;
        while(low <= high) {
            sum = numbers[low] + numbers[high]; 
            if( sum == target) {
                index.push_back(low + 1);
                index.push_back(high + 1);
                break;
            }
            else {
                if(sum < target) {
                    low++;
                }
                else {
                    high--;
                }
            }
        }
        return index;
    }
};

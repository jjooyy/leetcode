class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size < 2) {
            return 0;
        }
        else {
            int maxProfit = 0;
            int min = prices[0];
            for(int i = 1; i < size; i++) {
                maxProfit = max(maxProfit, prices[i] - min);
                if(prices[i] < min) {
                    min = prices[i];
                }
            }
            return maxProfit;
        }
    }
};

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        int count = 0;
        int i;
        for(i = 2; i * i < n; i++) {
            if(prime[i])  {
                count++;
                for(int j = i * 2; j<=n; j += i) {
                    prime[j] = false;
                }
            }
        }
        while(i<n) {
            if(prime[i]) {
                count++;
            }
            i++;
        }
        return count;
    }
};

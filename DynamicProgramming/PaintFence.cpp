class Solution {
public:
    int numWays(int n, int k) {
        if(n < 2 || !k) {
            return n * k;
        }
        int s = k;
        int d = k * (k - 1);
        for(int i = 2; i < n; i++) {
            int temp = s;
            s = d;
            d = (k - 1) * (temp + d);
        }
        return s + d;
    }
};

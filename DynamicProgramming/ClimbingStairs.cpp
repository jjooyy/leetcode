class Solution {
public:
    int climbStairs(int n) {
        if(n<3) {
            return n;
        }
        else {
            vector<int>methods(n+1, 0);
            methods[1] = 1;
            methods[2] = 2;
            for(int i=3; i<n+1; i++) {
                methods[i] = methods[i-1] + methods[i-2];
            }
            return methods[n];
        }
    }
};

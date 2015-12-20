class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) {
            return 1.0;
        }
        if(x == 1.0 ) {
            return 1.0;
        }
        else if(x == -1.0) {
            if(n & 1) {
                return x;
            }
            else return 1.0;
        }
        int power;
        double answer = 1.0;
        if(n < 0) {
            power = -n;
            x = 1 / x;
        }
        else {
            power = n;
        }
        while(power) {
            if(power & 1) {
                answer *= x;
            }
            x *= x;
            power >>= 1;
        }
        return answer;
    }
};

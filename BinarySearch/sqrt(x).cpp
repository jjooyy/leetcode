class Solution {
public:
    long long mySqrt(long long x) {
        if(x < 0) {
            return -1;
        }
        else if(!x) {
            return 0;
        }
        long long sq;
        long long l = 1;
        long long h = x / 2 + 1;
        while(l <= h) {
            sq = (h + l) / 2;
            if(sq * sq <= x && (sq+1) * (sq + 1) > x) {
                return sq;
            }
            else {
                if(sq * sq > x) {
                    h = sq - 1;
                }
                else {
                    l = sq + 1;
                }
            }
        }
        return -1;
    }
};

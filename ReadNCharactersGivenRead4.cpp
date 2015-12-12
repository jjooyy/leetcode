// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int count;
        int sum = 0;
        while((count = read4(buf)) &&(sum + count <= n + 3))  {
            int temp = count + sum <= n ? count : n - sum;
            buf += temp;
            sum += temp;
        }
        return sum;
    }
};

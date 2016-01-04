class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int sizea = a.size();
        int sizeb = b.size();
        int head = max(sizea, sizeb);
        string sum(head + 1, '0');
        int i = sizea - 1;
        int j = sizeb - 1;
        int it = head;
        while(i >= 0 || j >= 0 || carry) {
            int temp = 0;
            if(i >= 0) {
                temp += a[i] - '0';
                i--;
            }
            if(j >= 0) {
                temp += b[j] - '0';
                j--;
            }
            if(carry) {
                temp += carry;
            }
            carry = temp / 2;
            sum[it--] = temp % 2 + '0'; 
        }
        
        i = 0;
        while(sum[i] == '0' && i != head) {
            i++;
        }
        return sum.substr(i);
    }
};

class Solution {
public:
    string multiply(string num1, string num2) {
        int size1 = num1.size();
        int size2 = num2.size();
        string product(size1 + size2, '0');
        int temp;
        for(int i = size1 - 1; i >= 0; i--) {
            for(int j = size2 - 1; j >= 0; j--) {
                temp = product[i+j+1] - '0' + (num1[i] - '0') * (num2[j] - '0');
                product[i+j+1] = temp % 10 + '0';
                product[i+j] += temp / 10;
            }
        }
        int i = 0;
        while(product[i] == '0' && i != size1 + size2 - 1) {
            i++;
        }
        string t = product.substr(i);
        return t; 
    }
};

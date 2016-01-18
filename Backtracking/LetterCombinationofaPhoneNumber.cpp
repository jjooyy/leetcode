class Solution {
    string table[10] = {" ","", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    void helper(string digits, vector<string> &com, string temp, int start) {
        if(digits.size() == start) {
            com.push_back(temp);
            return;
        }
        for(int i = 0; i < table[digits[start]-'0'].size(); i++) {
            helper(digits, com, temp+table[digits[start]-'0'][i], start + 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> com;
        if(!digits.size()) {
            return com;
        }
        string temp;
        helper(digits, com, temp, 0);
        return com;
    }
};

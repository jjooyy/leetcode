class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        int size = s.size();
        vector<string> flip;
        if(size <= 1) {
            return flip;
        }
        for(int i = 0; i < size - 1; i++) {
            if(s[i] == '+' && s[i+1] == '+') {
                string temp = s;
                temp[i] = '-';
                temp[i+1] = '-';
                flip.push_back(temp);
            }
        }
        return flip;
    }
};

class Solution {
public:
    void genParenthesisUtil(vector<string> &out, int left, int right, string temp) {
        if(left==0&&right==0) {
            out.push_back(temp);
            return;
        }
        if(left>0) {
            genParenthesisUtil(out, left-1, right, temp+"(");
        }
        if(right>0&&right>left) {
            genParenthesisUtil(out, left, right-1, temp+")");
        }



    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> par;
        string temp = "";
        if(!n) {
            par.push_back(temp);
            return par;
        }
        genParenthesisUtil(par, n, n, temp);
        return par;
    }
};

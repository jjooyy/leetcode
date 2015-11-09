class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int size = preorder.size();
        if(size < 2) {
            return true;
        }
        stack<int> stk;
        int temp, i;
        temp = INT_MIN;
        stk.push(preorder[0]);
        i = 1;
        while(i < size) {
            if(stk.empty()||preorder[i]<stk.top()) {
                if(preorder[i]<temp) {
                    return false;
                }
                stk.push(preorder[i]);
                i++;
            }
            else {
                while((!stk.empty()) && preorder[i] > stk.top()) {
                    temp = stk.top();
                    stk.pop();
                }
            }
        }
        return true;
    }
};

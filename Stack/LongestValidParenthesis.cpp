class Solution {
public:
    int longestValidParentheses(string s) {
        int size = s.size();
        int left = 0;
        int maxLength = 0;
        stack<int> st;
        st.push(-1);
        int stop;
        for(int i = 0; i < size; i++) {
            stop = st.top();
            if((stop != -1) && s[stop] == '(' && s[i] == ')') {
                st.pop();
                maxLength = max(maxLength, i - st.top());
            }
            else {
                st.push(i);
            }
        }
        return maxLength;
    }
};

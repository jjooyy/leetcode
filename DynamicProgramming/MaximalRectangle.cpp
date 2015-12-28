class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(!matrix.size() || !matrix[0].size()) {
            return 0;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> height(col+1, 0);
        int max = 0;

        for(int i = 0; i < row; i++) {
            stack<int> myStack;
            for(int j = 0; j <= col; j++) {
                if(j < col) {
                    if(matrix[i][j] == '1') {
                        height[j]++;
                    }
                     else {
                        height[j] = 0;
                    }
                }
                if(myStack.empty() || height[myStack.top()] <= height[j]) {
                    myStack.push(j);
                }
                else {
                    while( (!myStack.empty()) && height[myStack.top()] > height[j]) {
                        int top = myStack.top();
                        myStack.pop();
                        int area = height[top] * (myStack.empty() ? j : (j - myStack.top() - 1));
                        if(area > max) {
                            max = area;
                        }    
                    }
                    myStack.push(j);
                }
            }
        }
        return max;
    }
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> out;
        if(!matrix.size()) {
            return out;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        int rowlow = 0;
        int collow = 0;
        int rowhigh = row - 1;
        int colhigh = col - 1;
        
        while(rowlow <= rowhigh && collow <= colhigh) {
            for(int i = collow; i <= colhigh; i++) {
                out.push_back(matrix[rowlow][i]);
            }
            rowlow++;
            if(rowhigh >= rowlow) {
                for(int i = rowlow; i <= rowhigh; i++) {
                    out.push_back(matrix[i][colhigh]);
                    
                }
                colhigh--;
            }
            if(colhigh >= collow && rowhigh >= rowlow) {
                for(int i = colhigh; i >= collow; i--) {
                    out.push_back(matrix[rowhigh][i]);
                    
                }
                rowhigh--;
            }
            if(rowhigh >= rowlow && colhigh >= collow) {
                for(int i = rowhigh; i >= rowlow; i--) {
                    out.push_back(matrix[i][collow]);
                    
                }
                collow++;
            }
        }
        return out;
    }
};

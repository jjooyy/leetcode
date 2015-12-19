class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(!row) {
            return false;
        }
        else {
            int col = matrix[0].size();
            if(!col) {
                return false;
            }
            int high = row - 1;
            int low = 0;
            int mid = 0;
            while(low <= high){
                mid = (low + high) / 2;
                if((mid < row - 1 && target >= matrix[mid][0] && target < matrix[mid+1][0])||(mid == row - 1 && target > matrix[mid][0])) {
                    if (target == matrix[mid][0]) {
                        return true;
                    }
                    break;
                }
                else if(target < matrix[mid][0]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            int midrow = mid;
            low = 0;
            high = col - 1;
            while (low <= high) {
                mid = (low + high)/2;
                if (target == matrix[midrow][mid]) {
                    return true;
                }
                else if(target < matrix[midrow][mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            return false;
        }
    }
};

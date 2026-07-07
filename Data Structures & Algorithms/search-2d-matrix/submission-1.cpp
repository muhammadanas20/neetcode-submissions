class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int cols = matrix[0].size();
        int rows = matrix.size();

        int low = 0;
        int high = (rows*cols)- 1;

        while(low <= high){
            int mid = low + (high - low)/2;

            //maping mid 1d to 2d r,c
            // mid/cols gives bounded row and mid%cols give bound col
            int r = mid/cols;
            int c = mid%cols;
            if(matrix[r][c] == target){
                return true;
            }
            else if(matrix[r][c] < target){
                low = mid + 1; //narrow to right
               
            }else{
                 high = mid - 1; //narrow to left
            }

        }
        return false;
    }
};

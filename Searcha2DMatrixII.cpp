class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        int x = matrix.size();
        int y = matrix[0].size();
        int row = 0, col = y-1;
        while(row <= x -1 &&  col >= 0){
            if(matrix[row][col] == target)  return true;
            else if(matrix[row][col] > target)  col--;
            else if(matrix[row][col] < target)  row++;
        }
        return false;
    }
};
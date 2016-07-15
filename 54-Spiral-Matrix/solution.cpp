class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rowSize = matrix.size();
        if (rowSize == 0) return res;
        
        int colSize = matrix[0].size();
        int leftb = 0, rightb = colSize - 1;
        int upb = 0, downb = rowSize - 1;
        
        int d = 0;
        int row = 0, col = 0;
        while (leftb <= rightb && upb <= downb) {
            res.push_back(matrix[row][col]);
            
            switch (d) {
                case 0: //right
                if (col >= rightb) {
                    d = 1;
                    row ++;
                    upb ++;
                } else col ++;
                break;
                
                case 1: //down
                if (row >= downb) {
                    d = 2;
                    col --;
                    rightb --;
                } else row ++;
                break;
                
                case 2: //left
                if (col <= leftb) {
                    d = 3;
                    row --;
                    downb --;
                } else col --;
                break;
                
                case 3: //up
                if (row <= upb) {
                    d = 0;
                    col ++;
                    leftb ++;
                } else row --;
            }
        }
        return res;
        
    }
};


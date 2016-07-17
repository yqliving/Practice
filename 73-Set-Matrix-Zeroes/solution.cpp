
/*
go through the matrix，遇到0时将第一行和第一列中对应的元素 mark 为 0，同时用两个 indicator 记录第一行和第一列是否出现 0；
zero rows (except the first row) according to the first column;
zero columns (except the first column) according to the first row;
zero first row and first column if needed. */


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row = false, col = false;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0) {
                    if(i == 0) row = true;
                    if(j == 0) col = true;
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        if(col){
            for(int i = 0; i < matrix.size(); i++) matrix[i][0] = 0;
        }
        if(row){
            for(int j = 0; j < matrix[0].size(); j++) matrix[0][j] = 0;
        }
    }
};
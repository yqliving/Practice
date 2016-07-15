class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    vector< vector <int> > mat(n);
    if (n<=0) return mat;
    /*for(int i=0; i<n; i++){
        vector<int> v(n);
        mat[i] = v;
    }*/

    int count = 1, row = n, col = n;
    int i = 0, j = -1;
    
    while (true) {
        for (int k = 0; k < col; k++)
            mat[i][++j] = count++;  // go right
        if (--row == 0)   break;
        for (int k = 0; k < row; k++)
            mat[++i][j] = count++;  // go down
        if (--col == 0)   break;
        for (int k = 0; k < col; k++)
            mat[i][--j] = count++;  // go left
        if (--row == 0)   break;
        for (int k = 0; k < row; k++)
            mat[--i][j] = count++;  // go up
        if (--col == 0)   break;
    }
    
    return mat;
}
};
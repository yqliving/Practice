class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    int N = matrix.size();
    int halfN = (N % 2 == 0) ? N / 2 : N / 2 + 1;
    for (int i = 0; i < halfN; i++) {
        for (int j = i; j < N - i - 1; j++) {
    //  for (int j = 0; j < N / 2; j++) { // alternative to replace the above line
            int k = N - i - 1, l = N - j - 1;
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[l][i];    // top   <- left
            matrix[l][i] = matrix[k][l];    // right <- top
            matrix[k][l] = matrix[j][k];    // down  <- right
            matrix[j][k] = tmp;             // left  <- down
        }
    }
        
    }
};

/*Time ~ O(N^2), Space ~ O(1) 
Rotate 90 clockwise: A -> B -> C -> D -> A
                         [i, j]
                     —  A  ————
                    |                          |
                    |                         B [j, n - 1 - i]
                    |                          |
                    |                          |
[n - j - 1, i]   D                         |
                    | ———— C —  |
                       [n - i - 1, n - 1 - j]
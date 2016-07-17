class Solution {
    public:
    bool exist(vector<vector<char>>& board, string word) {
        int lenR = board.size(), lenC = board[0].size();
        if (lenR == 0 || lenC == 0) return false;
        
        for (int i = 0; i < lenR; i++) {
            for (int j = 0; j < lenC; j++) {
                if (findWord(i, j, 0, word, board)) return true;
            }
            return false;
        }
    }
    
    private: 
    int lenR, lenC;
    bool findWord(int i, int j, int idx, string& word, vector<vector<char>>& board) {
        if (idx == word.size()) return true;
        if(i < 0 || j < 0 || i >= lenR || j >= lenC) return false;
        if(word[idx] != board[i][j]) return false;
        board[i][j] = '\0';
        if (findWord(i-1, j, idx+1, word, board) || 
            findWord(i+1, j, idx+1, word, board) || 
            findWord(i, j-1, idx+1, word, board) || 
            findWord(i, j+1, idx+1, word, board)) 
        return true;
        board[i][j] = word[idx];

        return false;
    }
};

//recursion
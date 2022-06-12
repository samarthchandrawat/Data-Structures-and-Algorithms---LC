class Solution {
public:
    
    bool rec_exist(vector<vector<char>>& board, string word, int i, int j, int pos) {
        
        if( i>=board.size() || i<0 || j>=board[0].size()  || j<0) {
            return false;
        }
        
        if(word[pos] != board[i][j]) {
            return false;
        }
        
        if(pos == word.length()-1) {
            return true;
        }
        
        board[i][j] = '#';
        
        if (rec_exist(board, word, i-1, j, pos+1) ||
                rec_exist(board, word, i+1, j, pos+1) ||
                rec_exist(board, word, i, j-1, pos+1) ||
                rec_exist(board, word, i, j+1, pos+1)) {
            return true;
        }
        
        board[i][j] = word[pos];
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
    
        int m = board.size();
        int n = board[0].size();
        
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                
                if(rec_exist(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
class Solution {
public:
    
    bool can_place(vector<vector<char>> &board, int i, int j, int n, char x) {
        
        for(int k=0; k<n; k++) {
            if(board[i][k] == x || board[k][j] ==x) 
                return false;
        }
        
        int sx = (i/3) * 3;
        int sy = (j/3) * 3;
        
        for(int k=sx; k<sx+3; k++) {
            for(int l=sy; l<sy+3; l++) {
                if(board[k][l] == x)
                    return false;
            }
        }
        
        return true;
    }
    
    bool solve_rec(vector<vector<char>> &board, int i, int j, int n) {
        
        if( i==n ) {
            return true;
        }
        
        if( j==n ) {
            return solve_rec(board, i+1, 0, n);
        }
        
        if( board[i][j] != '.' ) {
            return solve_rec(board, i, j+1, n);
        }
        
        for(int x=1; x<=9; x++) {
            
            if( can_place(board, i, j, n, to_string(x)[0]) ) {
                
                board[i][j] = to_string(x)[0];
                if(solve_rec(board, i, j+1, n)) {
                    return true;
                } else {
                    board[i][j] = '.';
                }
            }
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        solve_rec(board, 0, 0, 9);
        return;
    }
};
class Solution {
public:
    
    bool canPlace(vector<string> curr, int i, int j, int n) {
        
        //column empty
        for(int r=0; r<i; r++) {
            if(curr[r][j] == 'Q') {
                return false;
            }
        }
        
        //left diagonal
        int x = i, y = j;
        
        while(x>=0 && y>=0) {
            
            if(curr[x][y] == 'Q') {
                return false;
            }
            
            x--;
            y--;
        } 
        
        
        //right diagonal
        x = i, y = j;
        
        while(x>=0 && y<n) {
            
            if(curr[x][y] == 'Q') {
                return false;
            }
            
            x--;
            y++;
        }
        
        return true;
    }
    
    void queensRecursion(vector<vector<string>> &res, vector<string> &curr, int i, int n) {
        
        if(i == n) {
            
            res.push_back(curr);
            return;
        }
        
        for(int j=0; j<n; j++) {
            
            if( canPlace(curr, i, j, n) ) {
                
                curr[i][j] = 'Q';
                queensRecursion(res, curr, i+1, n);
                curr[i][j] = '.';
            }
        }
        
        return;
    }   
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> res;
        
        vector<string> curr(n, string(n, '.'));
        
        queensRecursion(res, curr, 0, n);    
        
        return res;
    }
};
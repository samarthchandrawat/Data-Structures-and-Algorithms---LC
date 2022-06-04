class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
    
        vector<int> row_1{1};
        res.push_back(row_1);

        if( n==1 )
            return res;

        vector<int> row_2{1,1};
        res.push_back(row_2);

        if( n==2 )
            return res;

        for(int i=3; i<=n; i++) {
            vector<int> curr_row;
            curr_row.push_back(1);
            for(int j=0; j<(res[i-2].size())-1; j++) {
                curr_row.push_back(res[i-2][j] + res[i-2][j+1]);
            }
            curr_row.push_back(1);
            res.push_back(curr_row);
        }
        return res;
    }
};
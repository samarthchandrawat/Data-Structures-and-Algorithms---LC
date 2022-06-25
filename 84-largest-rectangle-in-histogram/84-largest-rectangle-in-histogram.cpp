class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        vector<int> firstLessFromLeft(n, 0);
        firstLessFromLeft[0] = -1;
        
        for(int i=1; i<n; i++) {
            
            int temp = i-1;
            
            while(temp>=0 && heights[temp]>=heights[i]) {
                
                temp = firstLessFromLeft[temp];
            }
            
            firstLessFromLeft[i] = temp;
        }
        
        
        
        vector<int> firstLessFromRight(n, 0);
        firstLessFromRight[n-1] = n;
        
        for(int i=n-2; i>=0; i--) {
            
            int temp = i+1;
            
            while(temp<n && heights[temp]>=heights[i]) {
                
                temp = firstLessFromRight[temp];
            }
            
            firstLessFromRight[i] = temp;
        }
        
        int res = INT_MIN;
        
        for(int i=0; i<n; i++) {
            
            res = max(res,  (firstLessFromRight[i] - firstLessFromLeft[i] -1) *  heights[i]);
        }
        
        return res;
    }
};
//https://leetcode.com/problems/valid-mountain-array/
//dp solution for mountain array


class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n<3) return false;
        vector<int> dpStrictlyIncreasing(n,0);
        vector<int> dpStrictlyDecreasing(n,0);
        dpStrictlyIncreasing[0] = 1;
        dpStrictlyDecreasing[n-1] = 1;
        
        //increasing check
        for(int i=1; i<n; i++) {
            if((dpStrictlyIncreasing[i-1] == 1) &&
               (dpStrictlyIncreasing[i] > dpStrictlyIncreasing[i-1])) {
                dpStrictlyIncreasing[i] = 1;
            } else {
                dpStrictlyIncreasing[i] = 0;
            }
        }
        
        //decreasing check
        for(int i=n-2; i>=0; i++) {
            if((dpStrictlyDecreasing[i+1] == 1) &&
               (dpStrictlyDecreasing[i] > dpStrictlyDecreasing[i+1])) {
                dpStrictlyDecreasing[i] = 1;
            } else {
                dpStrictlyDecreasing[i] = 0;
            }
        }
        
        //mountain check
        for(int i=0; i<n; i++) {
            if(!((dpStrictlyDecreasing[i] == 1) &&
               (dpStrictlyIncreasing[i] == 1))) {
                    return false;
            }
        }
        
        return true;
};


// normal solution
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) 
            return false;
        int i = 0;
        while((i<n-1) && (arr[i] < arr[i+1]))
            i++;
        if(i==0 || i==n-1)
            return false;
        while((i<n-1) && (arr[i] > arr[i+1]))
            i++;
        if(i==n-1)
            return true;
        return false;
    }
};
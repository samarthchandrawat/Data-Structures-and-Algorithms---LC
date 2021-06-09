class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int m) {
        int n = flowerbed.size();
        int total = 0;
        if(n==1) {
            if(m==0)
                return true;
            if(m==1 && flowerbed[0]==0)
                return true;
            else
                return false;
        }
        for(int i=0; i<n; i++){
            if(i==0) {
                if(flowerbed[i]==0 && flowerbed[i+1]==0){
                    total++;
                    flowerbed[i]=1;
                }
            }
            if(0<i && i<n-1) {
                if(flowerbed[i-1]==0 && flowerbed[i]==0 && flowerbed[i+1]==0){
                    flowerbed[i]=1;
                    total++;
                }
            }
            if(i==n-1) {
                if(flowerbed[i]==0 && flowerbed[i-1]==0){
                    total++;
                    flowerbed[i]=1;
                }
            }
            if(total>=m) {
                return true;
            }
        }
        return false;
    }
};
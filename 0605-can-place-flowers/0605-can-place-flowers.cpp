class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int x=0;
        if(n==0){
            return true;
        }
        
        if(flowerbed.size()==1){
            if(flowerbed[0]==1){
            return false;}
            else{
                return true;
            }
        }
        if(flowerbed[0]==0 && flowerbed[1]==0){
            flowerbed[0]=1;
            x++;
        }
       for(int i=1;i<flowerbed.size()-1;i++){
           if((flowerbed[i-1]==0 && flowerbed[i+1]==0)&&(flowerbed[i]==0)){
               flowerbed[i]=1;
               x++;
           }
       }
        
        if(flowerbed[flowerbed.size()-2]==0 && flowerbed[flowerbed.size()-1]==0){
            x++;
        }
        if(x>=n){
            return true;
        }
        return false;
    }
};
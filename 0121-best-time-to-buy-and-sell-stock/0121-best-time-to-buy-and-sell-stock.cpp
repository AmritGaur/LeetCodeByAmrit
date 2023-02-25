class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int maxi=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<mini){
                mini=prices[i];
            }
            else{
                maxi=max(maxi,prices[i]-mini);
            }
        }
        return maxi;
    }
};
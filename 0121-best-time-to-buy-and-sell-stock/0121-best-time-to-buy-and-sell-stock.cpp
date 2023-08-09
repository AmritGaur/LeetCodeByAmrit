class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int profit=0;
        int sell=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]-buy>profit){
                sell=prices[i];
                profit=prices[i]-buy;
            }
            if(buy>prices[i]){
                buy=prices[i];
                sell=0;
            }
        }
        
        return profit;
    }
};
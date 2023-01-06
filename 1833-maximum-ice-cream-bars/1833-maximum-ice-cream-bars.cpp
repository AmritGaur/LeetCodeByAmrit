class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int n= costs.size();
        int x=coins;
        int count=0;
        for(int i=0;i<n;i++){
            if(x>=costs[i]){
                x=x-costs[i];
                count++;
            }
            else{
                return count;
            }
        }
        return count;
    }
};
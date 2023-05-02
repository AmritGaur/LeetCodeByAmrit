class Solution {
public:
    int arraySign(vector<int>& nums) {
        int pct=0;
        int nct=0;
        for(int it=0;it<nums.size();it++){
            if(nums[it]==0){
                return 0;
            }
            else if(nums[it]>0){
                pct++;
            }
            else{
                nct++;
            }
        }
        if(nct%2==0){
            return 1;
        }
        return -1;
    }
};
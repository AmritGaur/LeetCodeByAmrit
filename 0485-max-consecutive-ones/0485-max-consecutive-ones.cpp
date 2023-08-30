class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size()==1){
            if(nums[0]==1){
                return 1;
            }
            else{
                return 0;
            }
        }
        int x=0;
        for(int i=0;i<nums.size();i++){
            x+=nums[i];
        }
        if(x==0){
            return 0;
        }
        if(x==nums.size()){
            return x;
        }
        int ans=0;
        int lc=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                ans=max(ans,lc);
                lc=0;
            }
            else{
                lc++;
            }
        }
        ans=max(ans,lc);
        return ans;
    }
};
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long x=0;
        long long ans=0;
        bool flag;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                x++;
                flag=true;
            }
            else{
                ans+=(x*(x+1)/2);
                x=0;
                flag=false;
            }
            
        }
        if(flag){
            ans+=(x*(x+1)/2);
        }
        return ans;
    }
};